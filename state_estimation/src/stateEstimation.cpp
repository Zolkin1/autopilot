#include <chrono>

#include "stateEstimation.h"
#include "mbed.h"

void stateEstimationThread()
{
    std::chrono::milliseconds period(1000);
    DigitalOut led(LED1);
    Timer t;

    while (true)
    {
        t.start();

        // Recieve the data from the photon
        // Recieves X, Y, Z, and euler angles
        // just conver the euler angles into a rotation matrix and use the x,y,z coordinates as given
        

        led = !led;
        
        t.stop();

        std::chrono::milliseconds diff = std::chrono::duration_cast<std::chrono::milliseconds>(t.elapsed_time());
        ThisThread::sleep_for(period - diff);
    }    
}
