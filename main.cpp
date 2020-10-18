/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <string>
#include "log.h"

// Blinking rate in milliseconds
#define BLINKING_RATE       1000//ms

namespace logging
{
    Logger logger;
}

int main()
{
    // Initialise the digital pin LED1 as an output
    DigitalOut led(LED1);
    int a = 1;
    
    while (true) 
    {
        led = !led;
        ThisThread::sleep_for(BLINKING_RATE);
        std::string message = "Hello";
        logging::logger.log(message, "TYPE");
        a++;
    }

}
