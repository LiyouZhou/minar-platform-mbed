/*
 * PackageLicenseDeclared: Apache-2.0
 * Copyright (c) 2015 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MINAR_PLATFORM_TYPES_H
#define MINAR_PLATFORM_TYPES_H

#include <stdint.h>
#include "objects.h" //TODO: Replace by the proper target config file

namespace minar {
namespace platform {

enum Constants{
    // ticks per second (maximum resolution). This is what the OS works with.
    Time_Base = MINAR_PLATFORM_TIME_BASE,

#if YOTTA_CFG_MINAR_TEST_CLOCK_OVERFLOW
    // use only lower 16bits of timer for testing timer overflow
    Time_Mask = YOTTA_CFG_MINAR_TEST_CLOCK_OVERFLOW
#else
    // 32 bits of time for mbed platforms
    Time_Mask = 0xFFFFFFFFu
#endif
};

typedef uint32_t irqstate_t;

// Internal time type
typedef uint32_t tick_t;

namespace test {
#if YOTTA_CFG_MINAR_TEST_CLOCK_OVERFLOW
    uint32_t *get_sleep_until_buf(void);
    uint32_t get_sleep_until_buf_tail(void);
#endif
}; // namespace test

}; // namespace platform
}; // namespace minar

#endif // ndef MINAR_PLATFORM_TYPES_H
