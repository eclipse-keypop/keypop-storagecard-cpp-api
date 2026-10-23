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

#include "keypop/reader/CardReader.hpp"
#include "keypop/storagecard/card/ProductType.hpp"
#include "keypop/storagecard/card/StorageCard.hpp"
#include "keypop/storagecard/card/StorageCardSelectionExtension.hpp"
#include "keypop/storagecard/transaction/StorageCardTransactionManager.hpp"

namespace keypop {
namespace storagecard {

using keypop::reader::CardReader;
using keypop::storagecard::card::ProductType;
using keypop::storagecard::card::StorageCard;
using keypop::storagecard::card::StorageCardSelectionExtension;
using keypop::storagecard::transaction::StorageCardTransactionManager;

/**
 * Storage Card API Factory.
 *
 * @since 1.0.0
 */
class StorageCardApiFactory {
public:
    /**
     *
     */
    virtual ~StorageCardApiFactory() = default;

    /**
     * Creates a new instance of StorageCardSelectionExtension.
     *
     * @param productType The targeted product type.
     * @return A not null reference.
     * @since 1.0.0
     */
    virtual std::unique_ptr<StorageCardSelectionExtension>
    createStorageCardSelectionExtension(ProductType productType) = 0;

    /**
     * Creates an instance of StorageCardTransactionManager.
     *
     * @param reader The reader through which the card communicates.
     * @param card The initial card data provided by the selection process.
     * @return A not null reference.
     * @since 1.0.0
     */
    virtual std::unique_ptr<StorageCardTransactionManager>
    createStorageCardTransactionManager(
        const std::shared_ptr<CardReader>& reader,
        const std::shared_ptr<StorageCard>& card) = 0;
};

} /* namespace storagecard */
} /* namespace keypop */
