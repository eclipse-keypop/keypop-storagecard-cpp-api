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

#include <memory>
#include <string>

#include "keypop/reader/CardCommunicationException.hpp"
#include "keypop/storagecard/StorageCardException.hpp"

namespace keypop {
namespace storagecard {

using keypop::reader::CardCommunicationException;

/**
 * Indicates an input/output error that occurred while communicating with the
 * StorageCard.
 *
 * <p>This exception reflects errors in the card communication process, such
 * as transmission failures, card removal during processing, or any error
 * preventing the expected response from the card.
 *
 * <p>It is also thrown when an automatic verification read, performed after a
 * write operation on storage cards that do not provide reliable write
 * acknowledgment, fails to confirm that the expected data was correctly
 * stored.
 *
 * @since 1.0.0
 */
class SCCardCommunicationException final : public CardCommunicationException,
                                           public StorageCardException {
public:
    /**
     * Creates a new exception indicating a card communication error during
     * the execution of a storage card command.
     *
     * @param blockAddress The block address involved in the error, or
     * nullptr if not relevant.
     * @param message The message describing the exception context.
     * @since 1.0.0
     */
    SCCardCommunicationException(
        const std::shared_ptr<int>& blockAddress, const std::string& message)
    : CardCommunicationException(message)
    , mBlockAddress(blockAddress)
    {
    }

    /**
     * Creates a new exception indicating a card communication error during
     * the execution of a storage card command, with an underlying cause.
     *
     * @param blockAddress The block address involved in the error, or
     * nullptr if not relevant.
     * @param message The message describing the exception context.
     * @param cause The underlying cause of the exception.
     * @since 1.0.0
     */
    SCCardCommunicationException(
        const std::shared_ptr<int>& blockAddress,
        const std::string& message,
        const std::exception& cause)
    : CardCommunicationException(message, cause)
    , mBlockAddress(blockAddress)
    {
    }

    /**
     * {@inheritDoc}
     *
     * @since 1.0.0
     */
    std::shared_ptr<int>
    getBlockAddress() const override
    {
        return mBlockAddress;
    }

private:
    /**
     *
     */
    const std::shared_ptr<int> mBlockAddress;
};

} /* namespace storagecard */
} /* namespace keypop */
