#include <chrono>

#include "log.h"
#include "stateEstimation.h"
#include "mbed.h"

namespace estimation
{
    Mutex state_mutex;
    state q_state;
}

namespace logging
{
    extern Logger logger;
}

void stateEstimationThread()
{
    std::chrono::milliseconds period(100);
    DigitalOut led(LED1);
    Timer t;

    while (true)
    {
        t.start();

        // Recieve the data from the photon
        // Recieves X, Y, Z, and euler angles
        // just conver the euler angles into a rotation matrix and use the x,y,z coordinates as given

        estimation::state_mutex.lock();
        // update the state struct
        led = !led;
        estimation::state_mutex.unlock();
        
        t.stop();

        std::chrono::milliseconds diff = std::chrono::duration_cast<std::chrono::milliseconds>(t.elapsed_time());
        
        if (diff < period)
        {
            ThisThread::sleep_for(period - diff);
        }
    }    
}
