/******************************************************************************
 * Copyright (c) 2026 Calypso Networks Association https://calypsonet.org/    *
 *                                                                            *
 * This program and the accompanying materials are made available under the   *
 * terms of the MIT License which is available at                             *
 * https://opensource.org/licenses/MIT                                        *
 *                                                                            *
 * SPDX-License-Identifier: MIT                                               *
 ******************************************************************************/

#include <regex>
#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

/* Keypop Storage Card */
#include "keypop/storagecard/StorageCardApiProperties.hpp"

using keypop::storagecard::StorageCardApiProperties_VERSION;

TEST(StorageCardApiPropertiesTest, versionIsCorrectlyWritten)
{
    const std::string& apiVersion = StorageCardApiProperties_VERSION;
    const std::regex r("\\d+\\.\\d+");

    ASSERT_TRUE(std::regex_match(apiVersion, r));
}
