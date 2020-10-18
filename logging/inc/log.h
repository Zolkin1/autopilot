#include "mbed.h"
#include <string>

class Logger
{
    private:
        BufferedSerial serial;

    public:
        Logger();
        void log(std::string message, std::string type);
};
