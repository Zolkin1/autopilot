#include <chrono>

#include "log.h"
#include "stateEstimation.h"
#include "controller.h"
#include "mbed.h"

namespace estimation
{
    extern Mutex state_mutex;
    extern state q_state;
}

namespace logging
{
    extern Logger logger;
}

void controllerThread()
{
    std::chrono::milliseconds period(1000);     // period of the thread in milliseconds
    DigitalOut led(LED2);
    Timer t;

    while (true)
    {
        t.start();  // Start the timer
        // Start main loop code
        
        estimation::state_mutex.lock();
        led = !led;
        estimation::state_mutex.unlock();
    
        // End main loop code
        t.stop();   // Stop the timer

        std::chrono::milliseconds diff = std::chrono::duration_cast<std::chrono::milliseconds>(t.elapsed_time());
     
        if (diff < period)
        {
            ThisThread::sleep_for(period - diff);
        }
    }
}

