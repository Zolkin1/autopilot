/*
 * This file has the log class. This class will allow a log or debug message to be written to the openlog.
 */

#include "mbed.h"
#include <string>
#include <time.h>

#include "log.h"

Logger::Logger(): serial(PC_12, PD_2, 9600)
{

}

void Logger::log(std::string message, std::string type)
{
    time_t timer;
    timer = time(NULL);
    
    std::string t = std::to_string((unsigned int)timer);    // Gets time in seconds since boot
    std::string preamble = " " + type + ": ";
    int totalLength = message.length() + t.length() + preamble.length();
    char* arrMess = new char[totalLength+1];
    strcpy(arrMess, t.c_str());
    strcpy(arrMess + t.length(), preamble.c_str());
    strcpy(arrMess + t.length() + preamble.length(), message.c_str());
    strcpy(arrMess + totalLength, "\n");
    // Write the characters to the open log
    serial.write(arrMess, totalLength+1);
    delete arrMess;
}

