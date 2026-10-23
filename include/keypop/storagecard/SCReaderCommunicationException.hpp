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

#include "keypop/reader/ReaderCommunicationException.hpp"
#include "keypop/storagecard/StorageCardException.hpp"

namespace keypop {
namespace storagecard {

using keypop::reader::ReaderCommunicationException;

/**
 * Indicates an input/output error that occurred while communicating with the
 * card reader.
 *
 * <p>This exception reflects low-level reader communication failures, such
 * as a lost connection, hardware malfunction, or driver-related issues,
 * preventing the command from being transmitted to the StorageCard.
 *
 * @since 1.0.0
 */
class SCReaderCommunicationException final
: public ReaderCommunicationException,
  public StorageCardException {
public:
    /**
     * Creates a new exception indicating a reader communication error during
     * the execution of a storage card command.
     *
     * @param blockAddress The block address involved in the error, or
     * nullptr if not relevant.
     * @param message The message describing the exception context.
     * @since 1.0.0
     */
    SCReaderCommunicationException(
        const std::shared_ptr<int>& blockAddress, const std::string& message)
    : ReaderCommunicationException(message)
    , mBlockAddress(blockAddress)
    {
    }

    /**
     * Creates a new exception indicating a reader communication error during
     * the execution of a storage card command, with an underlying cause.
     *
     * @param blockAddress The block address involved in the error, or
     * nullptr if not relevant.
     * @param message The message describing the exception context.
     * @param cause The underlying cause of the exception.
     * @since 1.0.0
     */
    SCReaderCommunicationException(
        const std::shared_ptr<int>& blockAddress,
        const std::string& message,
        const std::exception& cause)
    : ReaderCommunicationException(message, cause)
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
