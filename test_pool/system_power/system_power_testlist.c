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
#include "val_interface.h"
#include "system_power_testlist.h"

test_fn_ptr system_power_test[] = {
    system_power_query_protocol_version,
    system_power_query_protocol_attributes,
    system_power_query_mandatory_command_support,
    system_power_state_get_check,
    system_power_invalid_messageid_call
};

test_fn_ptr *val_system_power_get_testlist(uint32_t *num_tests)
{
   *num_tests = NUM_ELEMS(system_power_test);
    return system_power_test;
}
