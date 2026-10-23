/******************************************************************************
 * Copyright (c) 2026 Calypso Networks Association https://calypsonet.org/    *
 *                                                                            *
 * This program and the accompanying materials are made available under the   *
 * terms of the MIT License which is available at                             *
 * https://opensource.org/licenses/MIT                                        *
 *                                                                            *
 * SPDX-License-Identifier: MIT                                               *
 ******************************************************************************/

#pragma once

#include <cstdint>
#include <vector>

#include "keypop/reader/selection/spi/CardSelectionExtension.hpp"
#include "keypop/storagecard/MifareClassicKeyType.hpp"
#include "keypop/storagecard/card/ProductType.hpp"

namespace keypop {
namespace storagecard {
namespace card {

using keypop::reader::selection::spi::CardSelectionExtension;
using keypop::storagecard::MifareClassicKeyType;

/**
 * Extends the CardSelectionExtension interface of the "Keypop Reader API" to
 * provide means to define optional commands to be executed during the
 * selection phase.
 *
 * @since 1.0.0
 */
class StorageCardSelectionExtension : public CardSelectionExtension {
public:
    /**
     *
     */
    virtual ~StorageCardSelectionExtension() = default;

    /**
     * Prepares the reading of a specific block from the storage card.
     *
     * <p>Block addresses start at 0 and the maximum value is equal to
     * ProductType::getBlockCount() - 1.
     *
     * <p>Once this command is processed, the result is available in
     * StorageCard.
     *
     * @param blockAddress The address of the block to be read.
     * @return The current instance.
     * @throw std::invalid_argument If the block address is out of range.
     * @since 1.0.0
     */
    virtual StorageCardSelectionExtension& prepareReadBlock(int blockAddress)
        = 0;

    /**
     * Prepares the reading of a range of blocks from the storage card.
     *
     * <p>Block addresses start at 0 and the maximum value is equal to
     * ProductType::getBlockCount() - 1.
     *
     * <p>Once this command is processed, the result is available in
     * StorageCard via the getBlock and getBlocks methods.
     *
     * @param fromBlockAddress The starting block address (inclusive).
     * @param toBlockAddress The ending block address (inclusive).
     * @return The current instance.
     * @throw std::invalid_argument If one of the arguments is out of range.
     * @since 1.0.0
     */
    virtual StorageCardSelectionExtension&
    prepareReadBlocks(int fromBlockAddress, int toBlockAddress) = 0;

    /**
     * Prepares the reading of the system block from an ST25/SRT512 storage
     * card.
     *
     * <p>This method is specific to ST25 and SRT512 card types which
     * provide access to a system block at address 255 containing
     * card-specific metadata and configuration data.
     *
     * <p>Once this command is processed, the result is available in
     * StorageCard via the getSystemBlock method.
     *
     * @return The current instance.
     * @throw std::logic_error If the current card type is not ST25/SRT512.
     * @since 1.2.0
     */
    virtual StorageCardSelectionExtension& prepareSt25ReadSystemBlock() = 0;

    /**
     * Prepares a Mifare Classic authentication command using a provided
     * key.
     *
     * <p>This method is specific to Mifare Classic cards and must be called
     * before reading from or writing to protected sectors. The
     * authentication applies to the entire sector containing the specified
     * block address.
     *
     * <p>The key must be a 6-byte array representing the Mifare Classic key
     * value.
     *
     * <p>When the key value is provided this way, it will be sent to the
     * reader to be stored as a volatile key at index 0 (see Load Key command
     * of the PC/SC standard). This volatile key is temporary and will be
     * erased after usage, when the reader is powered off.
     *
     * <p><strong>Security Note:</strong> This method transmits the key
     * value over the communication channel between the application and the
     * reader. For production environments and security-sensitive
     * applications, it is recommended to use the overload taking a key
     * number instead, which references a pre-stored key in the reader
     * without transmitting the key value.
     *
     * @param blockAddress The address of any block within the sector to
     * authenticate.
     * @param mifareClassicKeyType The type of key to use (Key A or Key B).
     * @param key The 6-byte key data for authentication.
     * @return The current instance.
     * @throw std::invalid_argument If the block address is out of range, or
     * if the key is not exactly 6 bytes long.
     * @throw std::logic_error If the current card type does not support
     * authentication.
     * @since 1.1.0
     */
    virtual StorageCardSelectionExtension& prepareMifareClassicAuthenticate(
        int blockAddress,
        MifareClassicKeyType mifareClassicKeyType,
        const std::vector<uint8_t>& key) = 0;

    /**
     * Prepares a Mifare Classic authentication command using a key stored
     * in the reader.
     *
     * <p>This method is specific to Mifare Classic cards and must be called
     * before reading from or writing to protected sectors. The
     * authentication applies to the entire sector containing the specified
     * block address.
     *
     * <p>The key is referenced by its storage index in the reader's key
     * storage. This allows using pre-configured keys without transmitting
     * them over the communication channel.
     *
     * @param blockAddress The address of any block within the sector to
     * authenticate.
     * @param mifareClassicKeyType The type of key to use (Key A or Key B).
     * @param keyNumber The index of the key in the reader's key storage.
     * @return The current instance.
     * @throw std::invalid_argument If the block address is out of range, or
     * if the key number is invalid.
     * @throw std::logic_error If the current card type does not support
     * authentication.
     * @since 1.1.0
     */
    virtual StorageCardSelectionExtension& prepareMifareClassicAuthenticate(
        int blockAddress,
        MifareClassicKeyType mifareClassicKeyType,
        int keyNumber) = 0;
};

} /* namespace card */
} /* namespace storagecard */
} /* namespace keypop */
