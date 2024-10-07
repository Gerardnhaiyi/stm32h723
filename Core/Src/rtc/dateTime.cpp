/***********************************************************************************************************************************
 *  File name          : dateTime.cpp
 *  Author             : GGT Nesselaar
 *
 *  Compiler           : STM32CubeIDE
 *  Manufacturer       : STMicroelectronics
 *  CreationDate       : Nov 29, 2023
 *
 *  File Description   : contains all methods used for the dateTime object
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
#include "dateTime.hpp"

/***********************************************************************************************************************************
 *  Used Prototypes    :
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *  Method Name        : dateTime
 *
 *  Method Description : Construct a new Date_Time object based on compressed date time format.
 *                       This is done based on the compressed format further explained in the detailed description of this class.
 *
 *  Entry              : compressedDateTime, The uint32_t compressed date time
 *                       milliseconds, The amount of miliseconds.
 *
 *  Exit               : None
 *
 **********************************************************************************************************************************/
dateTime::dateTime(const uint32_t &compressedDateTime, const uint16_t &milliseconds)
{
    d.year = ((compressedDateTime >> 26) & 0b111111) + startYear;
    d.month = (compressedDateTime >> 22) & 0b1111;
    d.day = (compressedDateTime >> 17) & 0b11111;
    t.hours = (compressedDateTime >> 12) & 0b11111;
    t.minutes = (compressedDateTime >> 6) & 0b111111;
    t.seconds = compressedDateTime & 0b111111;
    t.milliseconds = milliseconds;
}

/***********************************************************************************************************************************
 *  Method Name        : convertToUint32
 *
 *  Method Description : Compres the Date_Time object into the uint32_t notation.
 *                       This is done based on the compressed format further explained in the detailed description of this class.
 *
 *  Entry              : None
 *
 *  Exit               : uint32_t, The compressed Date_Time.
 *
 **********************************************************************************************************************************/
uint32_t dateTime::convertToUint32()
{
    return ((d.year - startYear) << 26) + (d.month << 22) + (d.day << 17) + (t.hours << 12) + (t.minutes << 6) + t.seconds;
}

/***********************************************************************************************************************************
 *  Method Name        : dateTimeToString
 *
 *  Method Description : Convert Date_Time object to string. Format DD-MM-YY, HH:MM:SS.MIL (25-03-2021, 19:25:30.999)
 *                       warning: Char buffer needs to be atleast 12 chars in size
 *
 *  Entry              : buffer, Char buffer to write to
 *                       bufferSize, Size of char buffer
 *
 *  Exit               : int, Number of bytes written to char buffer.
 *
 **********************************************************************************************************************************/
int dateTime::dateTimeToString(char *buffer, const size_t &bufferSize)
{
    if (bufferSize >= 24) 
    {
        return snprintf(buffer, bufferSize, "%02i-%02i-%04i, %02i:%02i:%02i.%03i", d.day, d.month, d.year, t.hours, t.minutes, t.seconds, t.milliseconds);
    }
    return 0;
}
