/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <string>

#include "log.h"
#include "controller.h"     // Controller thread
#include "stateEstimation.h"    // State Estimation thread

namespace logging
{
    // In theory the buffered serial class is thread safe, so I shoudln't need a mutex for the logger
    Logger logger;      // Global variable
}

Thread controller(osPriorityRealtime);
Thread stateEstimation(osPriorityHigh);

int main()
{   
    stateEstimation.start(callback(stateEstimationThread));
    controller.start(callback(controllerThread));
}
