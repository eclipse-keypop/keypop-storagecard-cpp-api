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

namespace keypop {
namespace storagecard {

/**
 * Interface for exceptions occurring during the execution of a command on a
 * StorageCard.
 *
 * <p>It provides additional context about the block address involved in the
 * error, when applicable.
 *
 * @since 1.0.0
 */
class StorageCardException {
public:
    /**
     *
     */
    StorageCardException() = default;

    /**
     *
     */
    StorageCardException(const StorageCardException&) = default;

    /**
     *
     */
    StorageCardException(StorageCardException&&) = default;

    /**
     *
     */
    StorageCardException& operator=(const StorageCardException&) = default;

    /**
     *
     */
    StorageCardException& operator=(StorageCardException&&) = default;

    /**
     *
     */
    virtual ~StorageCardException() = default;

    /**
     * Returns the address of the block involved in the error, if applicable.
     *
     * @return The block address that caused the error, or nullptr if not
     * relevant.
     * @since 1.0.0
     */
    virtual std::shared_ptr<int> getBlockAddress() const = 0;
};

} /* namespace storagecard */
} /* namespace keypop */
