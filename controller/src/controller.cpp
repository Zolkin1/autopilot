#include <chrono>

#include "controller.h"
#include "mbed.h"

void controllerThread()
{
    std::chrono::milliseconds period(100);     // period of the thread in milliseconds
    DigitalOut led(LED2);
    Timer t;

    while (true)
    {
        t.start();  // Start the timer
        // Start main loop code
        
        led = !led;
    
        // End main loop code
        t.stop();   // Stop the timer

        std::chrono::milliseconds diff = std::chrono::duration_cast<std::chrono::milliseconds>(t.elapsed_time());
        ThisThread::sleep_for(period - diff);
    }    
}

