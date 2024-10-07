/***********************************************************************************************************************************
 *  File name          : time.cpp
 *  Author             : GGT Nesselaar
 *
 *  Compiler           : STM32CubeIDE
 *  Manufacturer       : STMicroelectronics
 *  CreationDate       : Nov 29, 2023
 *
 *  File Description   : contains all methods used for the time object
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *  Used Defines       : 
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *  Used Includes      : 
 **********************************************************************************************************************************/
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <cmath>
#include "time.hpp"

/***********************************************************************************************************************************
 *  Used Prototypes    :
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *  Method Name        : timeToString
 *
 *  Method Description : Convert Time object to string. Format HH:MM:SS.MIL (19:25:30.999)
 *                       warning: Char buffer needs to be atleast 12 chars in size
 *
 *  Entry              : buffer, Char buffer to write to
 *                       bufferSize, Size of char buffer
 *
 *  Exit               : int, Number of bytes written to char buffer.
 *
 **********************************************************************************************************************************/
int time::timeToString(char *buffer, const size_t &bufferSize)
{
    if (bufferSize >= 12) 
    {
        return snprintf(buffer, bufferSize, "%02i:%02i:%02i.%03i", hours, minutes, seconds, milliseconds);
    }
    return 0;
}

/***********************************************************************************************************************************
 *  Method Name        : timeToSeconds
 *
 *  Method Description : Calculate time in seconds from 00:00:00.000 as starting point. ms are rounded to 100ms. so 89ms will be 100.
 *
 *  Entry              : None
 *
 *  Exit               : float, Time in seconds with ms as a decimal, so 4500.9s means 4500s and 900ms.
 *
 **********************************************************************************************************************************/
float time::timeToSeconds()
{
    return (hours * 60 * 60) + (minutes * 60) + seconds + ((float) (((milliseconds + 100 / 2) / 100) * 100) / 1000);
}
