/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <string>

#include "log.h"
#include "controller.h"     // Controller thread
#include "stateEstimation.h"    // State Estimation thread


Logger logger;      // Global variable


Thread controller;
Thread stateEstimation;

int main()
{   
    stateEstimation.start(callback(stateEstimationThread));
    controller.start(callback(controllerThread));
}
