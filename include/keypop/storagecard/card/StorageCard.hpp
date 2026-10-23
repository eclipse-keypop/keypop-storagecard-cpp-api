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
#include <memory>
#include <vector>

#include "keypop/reader/selection/spi/SmartCard.hpp"
#include "keypop/storagecard/card/ProductType.hpp"

namespace keypop {
namespace storagecard {
namespace card {

using keypop::reader::selection::spi::SmartCard;

/**
 * Represents a storage card with various methods to retrieve information and
 * data from it.
 *
 * @since 1.0.0
 */
class StorageCard : public SmartCard {
public:
    /**
     *
     */
    virtual ~StorageCard() = default;

    /**
     * Returns the product type of the storage card.
     *
     * @return The product type of the storage card.
     * @since 1.0.0
     */
    virtual ProductType getProductType() const = 0;

    /**
     * Retrieves the unique identifier (UID) of the storage card.
     *
     * @return A byte array representing the UID of the storage card.
     * @since 1.0.0
     */
    virtual std::vector<uint8_t> getUID() const = 0;

    /**
     * Retrieves the system block from the storage card when available.
     *
     * <p>The system block contains card-specific metadata and configuration
     * data such as access control settings. This feature is specific to
     * ST25/SRT512 cards which provide access to a system block at address
     * 255.
     *
     * <p>The system block must have been previously read using the
     * StorageCardSelectionExtension::prepareSt25ReadSystemBlock() method (or
     * the deprecated
     * StorageCardTransactionManager::prepareReadSystemBlock() method).
     *
     * @return The system block data as a byte array, or nullptr if the
     * system block has not been read yet.
     * @throw std::logic_error If the current card type does not support
     * system block access.
     * @since 1.0.0
     */
    virtual std::shared_ptr<std::vector<uint8_t>> getSystemBlock() const = 0;

    /**
     * Retrieves the data block at the specified block address.
     *
     * <p>If the block has not been previously read and stored in memory,
     * the returned byte array will be filled with zeros.
     *
     * @param blockAddress The address of the block to retrieve.
     * @return The data block as a byte array, or a zero-filled byte array
     * if the block has not been read yet.
     * @throw std::out_of_range If the block address is out of range.
     * @since 1.0.0
     */
    virtual std::vector<uint8_t> getBlock(int blockAddress) const = 0;

    /**
     * Retrieves the data blocks within the specified range from the memory
     * image of the storage card.
     *
     * <p>The returned array contains the blocks in order, from
     * fromBlockAddress to toBlockAddress. If a block has not been previously
     * read and stored in memory, its corresponding bytes in the returned
     * array will be filled with zeros.
     *
     * @param fromBlockAddress The starting block address (inclusive).
     * @param toBlockAddress The ending block address (inclusive).
     * @return A byte array containing the data blocks within the specified
     * range. Unread blocks are represented as zero-filled sections in the
     * returned array.
     * @throw std::out_of_range If fromBlockAddress is greater than
     * toBlockAddress, if either block address is negative, or if they
     * exceed the available range of the memory image.
     * @since 1.0.0
     */
    virtual std::vector<uint8_t>
    getBlocks(int fromBlockAddress, int toBlockAddress) const = 0;
};

} /* namespace card */
} /* namespace storagecard */
} /* namespace keypop */
