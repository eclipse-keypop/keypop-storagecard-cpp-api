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
 * Indicates that an authentication attempt on a StorageCard has failed.
 *
 * <p>This exception is thrown when authentication to a Mifare Classic sector
 * fails, typically due to incorrect key data or key type. Authentication is
 * required before reading from or writing to protected sectors on Mifare
 * Classic cards.
 *
 * @since 1.1.0
 */
class SCAuthenticationFailedException final : public CardCommunicationException,
                                              public StorageCardException {
public:
    /**
     * Creates a new exception indicating an authentication failure during
     * the execution of a storage card command.
     *
     * @param blockAddress The block address involved in the error, or
     * nullptr if not relevant.
     * @param message The message describing the exception context.
     * @since 1.1.0
     */
    SCAuthenticationFailedException(
        const std::shared_ptr<int>& blockAddress, const std::string& message)
    : CardCommunicationException(message)
    , mBlockAddress(blockAddress)
    {
    }

    /**
     * Creates a new exception indicating an authentication failure during
     * the execution of a storage card command, with an underlying cause.
     *
     * @param blockAddress The block address involved in the error, or
     * nullptr if not relevant.
     * @param message The message describing the exception context.
     * @param cause The underlying cause of the exception.
     * @since 1.1.0
     */
    SCAuthenticationFailedException(
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
     * @since 1.1.0
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
