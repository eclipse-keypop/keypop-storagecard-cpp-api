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

/**
 * Enumeration of the Mifare Classic key types used for authentication.
 *
 * <p>Mifare Classic cards support two types of keys per sector for access
 * control: Key A and Key B. Each sector can be protected independently using
 * these keys, allowing fine-grained access control.
 *
 * @since 1.1.0
 */
enum class MifareClassicKeyType {
    /**
     * Key A type.
     *
     * <p>This is the primary key used for authentication to a Mifare Classic
     * sector. In most configurations, Key A has read/write permissions while
     * Key B may have restricted permissions.
     *
     * @since 1.1.0
     */
    KEY_A,

    /**
     * Key B type.
     *
     * <p>This is the secondary key used for authentication to a Mifare
     * Classic sector. Key B is often used for restricted operations or
     * read-only access, depending on the sector's access conditions.
     *
     * @since 1.1.0
     */
    KEY_B
};

} /* namespace storagecard */
} /* namespace keypop */
