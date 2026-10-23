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

#include "keypop/reader/selection/InvalidCardResponseException.hpp"
#include "keypop/storagecard/StorageCardException.hpp"

namespace keypop {
namespace storagecard {

using keypop::reader::selection::InvalidCardResponseException;

/**
 * Indicates that a command returned an unexpected or invalid status while
 * interacting with the StorageCard.
 *
 * <p>This exception is typically thrown when the card responds with a status
 * code that does not match the expected outcome of the executed command,
 * suggesting that the operation could not be completed as intended (e.g.,
 * write or read command rejected by the card).
 *
 * @since 1.0.0
 */
class SCInvalidCardResponseException final
: public InvalidCardResponseException,
  public StorageCardException {
public:
    /**
     * Creates a new exception indicating a card status code error during the
     * execution of a storage card command.
     *
     * @param blockAddress The block address involved in the error, or
     * nullptr if not relevant.
     * @param message The message describing the exception context.
     * @since 1.0.0
     */
    SCInvalidCardResponseException(
        const std::shared_ptr<int>& blockAddress, const std::string& message)
    : InvalidCardResponseException(message)
    , mBlockAddress(blockAddress)
    {
    }

    /**
     * Creates a new exception indicating a card status code error during the
     * execution of a storage card command, with an underlying cause.
     *
     * @param blockAddress The block address involved in the error, or
     * nullptr if not relevant.
     * @param message The message describing the exception context.
     * @param cause The underlying cause of the exception.
     * @since 1.0.0
     */
    SCInvalidCardResponseException(
        const std::shared_ptr<int>& blockAddress,
        const std::string& message,
        const std::exception& cause)
    : InvalidCardResponseException(message, cause)
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
