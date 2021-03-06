/** @file
 * Copyright (c) 2019, Arm Limited or its affiliates. All rights reserved.
 * SPDX-License-Identifier : Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
**/

#ifndef __CLOCK_TESTLIST_H__
#define __CLOCK_TESTLIST_H__

uint32_t clock_query_protocol_version(void);
uint32_t clock_query_protocol_attributes(void);
uint32_t clock_query_mandatory_command_support(void);
uint32_t clock_attributes_check(void);
uint32_t clock_rate_get_check(void);
uint32_t clock_config_set_check(void);
uint32_t clock_invalid_messageid_call(void);

#endif
