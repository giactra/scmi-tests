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

#include"val_interface.h"

#define TEST_NUM  (SCMI_POWER_DOMAIN_TEST_NUM_BASE + 1)
#define TEST_DESC "Power domain protocol version check                    "

uint32_t power_domain_query_protocol_version(void)
{
    int32_t status;
    uint32_t rsp_msg_hdr, cmd_msg_hdr;
    uint32_t param_count, *parameters;
    uint32_t return_value_count, version, expected_version;

    if (val_test_initialize(TEST_NUM, TEST_DESC) != VAL_STATUS_PASS)
        return VAL_STATUS_SKIP;

    /* Check power domain protocol version */

    val_print(VAL_PRINT_DEBUG, "\n\t[Check 1] Query protocol version");

    VAL_INIT_TEST_PARAM(param_count, rsp_msg_hdr, return_value_count, status);
    parameters = NULL;
    version = 0;
    cmd_msg_hdr = val_msg_hdr_create(PROTOCOL_POWER_DOMAIN, PD_PROTOCOL_VERSION, COMMAND_MSG);
    val_send_message(cmd_msg_hdr, param_count, parameters, &rsp_msg_hdr, &status,
                     &return_value_count, &version);

    if (val_compare_status(status, SCMI_SUCCESS) != VAL_STATUS_PASS)
        return VAL_STATUS_FAIL;

    if (val_compare_msg_hdr(rsp_msg_hdr, cmd_msg_hdr) != VAL_STATUS_PASS)
        return VAL_STATUS_FAIL;

    expected_version =  val_power_domain_get_expected_protocol_version();
    if (val_protocol_version_check(expected_version, version) != VAL_STATUS_PASS)
        return VAL_STATUS_FAIL;

    return VAL_STATUS_PASS;
}
