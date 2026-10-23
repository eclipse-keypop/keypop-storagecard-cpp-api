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

namespace keypop {
namespace storagecard {
namespace card {

/**
 * Represents the different types of storage cards supported by the library.
 *
 * @since 1.0.0
 */
class ProductType {
public:
    /**
     * NXP Mifare Ultralight
     *
     * @since 1.0.0
     */
    static const ProductType MIFARE_ULTRALIGHT;

    /**
     * NXP Mifare Classic 1K
     *
     * @since 1.1.0
     */
    static const ProductType MIFARE_CLASSIC_1K;

    /**
     * NXP Mifare Classic 4K
     *
     * @since 1.1.0
     */
    static const ProductType MIFARE_CLASSIC_4K;

    /**
     * ST Microelectronics ST25 / SRT512
     *
     * @since 1.0.0
     */
    static const ProductType ST25_SRT512;

    /**
     * Returns the number of blocks in a storage card of this product type.
     *
     * <p>This number reflects the quantity of blocks contained in the main
     * memory area. Please note that there might be additional "system"
     * blocks not included in this count.
     *
     * @return The number of blocks in the storage card.
     * @since 1.0.0
     */
    int
    getBlockCount() const
    {
        return mBlockCount;
    }

    /**
     * Returns the size of each block in bytes for this product type.
     *
     * @return The size of each block in bytes.
     * @since 1.0.0
     */
    int
    getBlockSize() const
    {
        return mBlockSize;
    }

    /**
     * Indicates whether this product type has an accessible system block.
     *
     * <p>For ST25/SRT512 cards, the system block is accessible at address
     * 255. For MIFARE Ultralight and Mifare Classic cards, no system block
     * is accessible through the API.
     *
     * <p>When a system block is available, it can be read using the
     * appropriate prepare methods during card selection or transaction
     * processing.
     *
     * @return true if this product type has an accessible system block,
     * false otherwise.
     * @since 1.0.0
     */
    bool
    hasSystemBlock() const
    {
        return mHasSystemBlock;
    }

    /**
     * Indicates whether this product type provides a reliable
     * acknowledgment after write operations.
     *
     * <p>If this method returns true, the card guarantees that a successful
     * response to a write command means the data has been correctly stored,
     * and no additional verification is required. If it returns false, the
     * card does not guarantee the actual completion of the write, and a
     * verification read must be performed to ensure data consistency.
     *
     * @return true if the card provides a reliable write acknowledgment,
     * false otherwise.
     * @since 1.0.0
     */
    bool
    hasWriteAcknowledgment() const
    {
        return mHasWriteAcknowledgment;
    }

    /**
     * Indicates whether this product type requires authentication before
     * read/write operations.
     *
     * <p>If this method returns true, the card requires successful
     * authentication to a sector before read or write operations can be
     * performed on blocks within that sector. For Mifare Classic cards,
     * authentication must be performed using Key A or Key B with the
     * appropriate authentication methods.
     *
     * <p>If this method returns false, the card allows direct read/write
     * operations without prior authentication.
     *
     * @return true if the card requires authentication, false otherwise.
     * @since 1.1.0
     */
    bool
    hasAuthentication() const
    {
        return mHasAuthentication;
    }

    /**
     * Compares this product type to another for equality.
     *
     * @param other The product type to compare to.
     * @return true if both refer to the same product type, false otherwise.
     * @since 1.2.0
     */
    bool
    operator==(const ProductType& other) const
    {
        return this == &other;
    }

    /**
     * Compares this product type to another for inequality.
     *
     * @param other The product type to compare to.
     * @return true if the product types differ, false otherwise.
     * @since 1.2.0
     */
    bool
    operator!=(const ProductType& other) const
    {
        return !(*this == other);
    }

private:
    /**
     *
     */
    int mBlockCount;

    /**
     *
     */
    int mBlockSize;

    /**
     *
     */
    bool mHasSystemBlock;

    /**
     *
     */
    bool mHasWriteAcknowledgment;

    /**
     *
     */
    bool mHasAuthentication;

    /**
     * Constructor.
     *
     * @param blockCount The number of blocks in the storage card.
     * @param blockSize The size of each block in bytes.
     * @param hasSystemBlock Whether this card type has an accessible system
     * block.
     * @param hasWriteAcknowledgment Whether this card provides a reliable
     * acknowledgment confirming successful write operations.
     * @param hasAuthentication Whether this card type requires authentication
     * before read/write operations.
     */
    ProductType(
        int blockCount,
        int blockSize,
        bool hasSystemBlock,
        bool hasWriteAcknowledgment,
        bool hasAuthentication)
    : mBlockCount(blockCount)
    , mBlockSize(blockSize)
    , mHasSystemBlock(hasSystemBlock)
    , mHasWriteAcknowledgment(hasWriteAcknowledgment)
    , mHasAuthentication(hasAuthentication)
    {
    }
};

const ProductType ProductType::MIFARE_ULTRALIGHT(16, 4, false, true, false);
const ProductType ProductType::MIFARE_CLASSIC_1K(64, 16, false, true, true);
const ProductType ProductType::MIFARE_CLASSIC_4K(256, 16, false, true, true);
const ProductType ProductType::ST25_SRT512(16, 4, true, false, false);

} /* namespace card */
} /* namespace storagecard */
} /* namespace keypop */
