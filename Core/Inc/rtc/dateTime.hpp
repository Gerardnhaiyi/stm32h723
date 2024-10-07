/***********************************************************************************************************************************
 *  File name          : dateTime.hpp
 *  Author             : GGT Nesselaar
 *
 *  Compiler           : STM32CubeIDE
 *  Manufacturer       : STMicroelectronics
 *  CreationDate       : Nov 29, 2023
 *
 **********************************************************************************************************************************/
#ifndef INC_RTC_DATE_TIME_HPP_

/***********************************************************************************************************************************
 *  Used defines       : 
 **********************************************************************************************************************************/
    #define	INC_RTC_DATE_TIME_HPP_

	#define startYear  2000

/***********************************************************************************************************************************
 *  Used includes      :
 **********************************************************************************************************************************/
#include <cstdint>
#include <cstring>
#include <cmath>
#include "date.hpp"
#include "time.hpp"

/***********************************************************************************************************************************
 *  Used constants    :
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *	enum name          : 
 *
 *  enum Description   : 
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *	array name         :
 *
 *  array Description  :
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *	struct name        :
 *
 *	struct Description :
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *	Class name         : dateTime
 *
 *  Class Description  : Simple date and time storage class.
 *                       This combines the Time and Date class into one with added functionality.\n
 *                       This class allows for compressing a full date_time object into one uint32_t and one uint16_t.\n
 *                       This is done based on the structure below:
 *                       Uint32 for date time is based on the following sequence
 *                       Bit possition   Data
 *                       31-26           year with 2020 as base so a value of 1 means 2021
 *                       25-22           month
 *                       21-17           day
 *                       16-12           hours
 *                       11-6            minutes
 *                       5-0             seconds
 *                       The miliseconds will be stored in the sepperate uint16_t
 *
 *	Inheritance        : None
 *
 **********************************************************************************************************************************/
class dateTime 
{
    public:
        // This is used to convert a date time object to uint32_t.
        date d;
        time t;

        /***********************************************************************************************************************************
         *  Method Name        : dateTime
         *
         *  Method Description : Construct a new Date_Time object
         *
         *  Entry              : None
         *
         *  Exit               : None
         *
         **********************************************************************************************************************************/
        dateTime(void) {}; //Construct a new Date_Time object

        /***********************************************************************************************************************************
         *  Method Name        : dateTime
         *
         *  Method Description : Construct a new Date_Time object
         *
         *  Entry              : d Filled Date object.
         *                       t Filled Time object.
         *
         *  Exit               : None
         *
         **********************************************************************************************************************************/
        dateTime(const date &d, const time &t) : d(d), t(t) {}

        dateTime(const uint32_t &compressedDateTime, const uint16_t &milliseconds); //Construct a new Date_Time object based on compressed date time format.
        uint32_t convertToUint32(void); //Compres the Date_Time object into the uint32_t notation.
        int dateTimeToString(char *buffer, const size_t &bufferSize); //Convert Date_Time object to string.

        /***********************************************************************************************************************************
         *  Method Name        : operator =
         *
         *  Method Description : Overloaded = operator to allow the assignment of a Date_Time object.
         *
         *  Entry              : rhs, The other object that needs to be assign to the current.
         *
         *  Exit               : None
         *
         **********************************************************************************************************************************/
        void operator =(const dateTime &other)
        {
            d = other.d;
            t = other.t;
        }

        /***********************************************************************************************************************************
         *  Method Name        : operator >
         *
         *  Method Description : Overloaded operator for greater then. This uses the overloaded operators from the Time and Date classes.
         *
         *  Entry              : rhs, other object
         *
         *  Exit               : true, LHS is later then RHS
         *  					 false, RHS is later then LHS
         *
         **********************************************************************************************************************************/
        bool operator > (const dateTime &rhs)
        const   {
                    return (d > rhs.d) ? true : (d == rhs.d && t > rhs.t);
                }

        /***********************************************************************************************************************************
         *  Method Name        : operator ==
         *
         *  Method Description : Overloaded operator for equals. This uses the overloaded operators from the Time and Date classes.
         *
         *  Entry              : rhs, other object
         *
         *  Exit               : true, if time and date are the same.
         *  					 false, if time or date differs.
         *
         **********************************************************************************************************************************/
        bool operator == (const dateTime &rhs)
        const   {
                    return (t == rhs.t) && (d == rhs.d);
                }
};

/***********************************************************************************************************************************
 *  Prototypes         :
 **********************************************************************************************************************************/


    
#endif	/* INC_RTC_DATE_TIME_HPP_ */

