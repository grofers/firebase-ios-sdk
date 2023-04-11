/*
 * Copyright 2023 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import "FIRAggregateField.h"
#import "FIRFieldPath.h"

#include "Firestore/core/src/model/aggregate_field.h"

#include <string>

NS_ASSUME_NONNULL_BEGIN

namespace model = firebase::firestore::model;

@interface FIRAggregateField (Internal)
  @property(nonatomic, strong, readonly) FIRFieldPath *_fieldPath;
  - (model::AggregateField)createInternalValue;
  - (model::AggregateAlias)createAlias;
  - (const std::string)name;
@end

/**
 * FIRAggregateField class for sum aggregations. Exposed internally so code can do isKindOfClass
 * checks on it.
 */
@interface FSTSumAggregateField : FIRAggregateField
- (instancetype)init NS_UNAVAILABLE;
- (id)initWithFieldPath:(FIRFieldPath *)path;
- (model::AggregateField)createInternalValue;
- (model::AggregateAlias)createAlias;
- (const std::string)name;
@end

/**
 * FIRAggregateField class for average aggregations. Exposed internally so code can do isKindOfClass
 * checks on it.
 */
@interface FSTAverageAggregateField : FIRAggregateField
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithFieldPath:(FIRFieldPath *)internalFieldPath;
- (model::AggregateField)createInternalValue;
- (model::AggregateAlias)createAlias;
- (const std::string)name;
@end

/** FIRAggregateField class for count aggregations. Exposed internally so code can do isKindOfClass
 * checks on it.
 */
@interface FSTCountAggregateField : FIRAggregateField
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initPrivate;
- (model::AggregateField)createInternalValue;
- (model::AggregateAlias)createAlias;
- (const std::string)name;
@end

NS_ASSUME_NONNULL_END