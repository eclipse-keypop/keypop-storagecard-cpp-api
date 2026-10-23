/******************************************************************************
 * Copyright (c) 2026 Calypso Networks Association https://calypsonet.org/    *
 *                                                                            *
 * This program and the accompanying materials are made available under the   *
 * terms of the MIT License which is available at                             *
 * https://opensource.org/licenses/MIT                                        *
 *                                                                            *
 * SPDX-License-Identifier: MIT                                               *
 ******************************************************************************/

#include <iostream>

#include "keypop/storagecard/StorageCardApiProperties.hpp"
#include "keypop/storagecard/card/StorageCardSelectionExtension.hpp"

int
main()
{
    /* StorageCardSelectionExtension transitively pulls in
     * keypop-reader-cpp-api's CardSelectionExtension header; referencing the
     * type here proves the
     * transitive dependency resolves through Conan/CMake alone. */
    using keypop::storagecard::card::StorageCardSelectionExtension;

    std::cout << "Keypop::StorageCard header-only package resolved and linked "
                 "correctly (API version "
              << keypop::storagecard::StorageCardApiProperties_VERSION << ")"
              << std::endl;
    return 0;
}
