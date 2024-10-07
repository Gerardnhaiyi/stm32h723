/***********************************************************************************************************************************
 *  File name        : rtc.hpp
 *  Author           : GGT Nesselaar
 *
 *  Compiler         : STM32CubeIDE
 *  Manufacturer     : STMicroelectronics
 *  CreationDate     : Nov 29, 2023
 *
 **********************************************************************************************************************************/
#ifndef INC_RTC_RTC_HPP_

/***********************************************************************************************************************************
 *  Used defines       : 
 **********************************************************************************************************************************/
    #define	INC_RTC_RTC_HPP_

/***********************************************************************************************************************************
 *  Used includes      :
 **********************************************************************************************************************************/
#include <cstdint>
#include <cstring>
#include <cmath>
#include "rtc.h"
#include "dateTime.hpp"
#include "date.hpp"
#include "time.hpp"

/***********************************************************************************************************************************
 *  Used constants    :
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *	 enum name         : rtcBkpReg
 *
 *   enum Description  : enumeration of RTC memory spaces (in total 32 * 4 bytes)
 *
 **********************************************************************************************************************************/
	enum class rtcBkpReg : uint8_t
	{
		PARAM_STORAGE_FLASH_ADDR = 0, //0
		LOG_DAY_0, //first flash address of day 0
		LOG_DAY_1, //first flash address of day 1
		LOG_DAY_2, //first flash address of day 2
		LOG_DAY_3, //first flash address of day 3
		LOG_DAY_4, //first flash address of day 4
		LOG_DAY_5, //first flash address of day 5
		LOG_DAY_6, //first flash address of day 6
		LOG_CURRENT_DAY_POINTER, //point to active day (0..6)
		NOT_USED_16,
		FAULT_CODE, //10 //see adjacent table
		TIME_STAMP_FAULT_CODE,
		SETPOINT_VALUE, //value of current setpoint
		STATUS_CODE, //led status
		WATCHDOG_CODE, //fault-code of the watchdog is stored here for sourcing
		ALARM_POINTER, //15
		NOT_USED_15,
		NOT_USED_14,
		NOT_USED_13,
		NOT_USED_12,
		NOT_USED_11, //20
		NOT_USED_10,
		NOT_USED_09,
		NOT_USED_08,
		NOT_USED_07,
		NOT_USED_06, //25
		NOT_USED_05,
		NOT_USED_04,
		NOT_USED_03,
		NOT_USED_02,
		DFU_BOOT_KEY, //30
		NOT_USED_01 //31
	};

	/* fault code table
	 * bit	description
	 * 	0	The processor attempted an instruction fetch from a location that does not permit execution.
	 *	1	The processor attempted a load or store at a location that does not permit the operation.
	 *	3	Unstack for an exception return has caused one or more access violations.
	 *	4	Stacking for an exception entry has caused one or more access violations.
	 *	5	A MemManage fault occurred during floating-point lazy state preservation.
	 *	7	MMAR holds a valid fault address.
	 *	8	Instruction bus error.
	 *	9	A data bus error has occurred, and the PC value stacked for the exception return points to the instruction that caused the fault.
	 *	10	A data bus error has occurred, but the return address in the stack frame is not related to the instruction that caused the error.
	 *	11	Unstack for an exception return has caused one or more BusFaults.
	 *	12	Stacking for an exception entry has caused one or more BusFaults.
	 *	13	A bus fault occurred during floating-point lazy state preservation.
	 *	15	BFAR holds a valid fault address.
	 *	16	The processor has attempted to execute an undefined instruction.
	 *	17	The processor has attempted to execute an instruction that makes illegal use of the EPSR.
	 *	18	The processor has attempted an illegal load of EXC_RETURN to the PC, as a result of an invalid context, or an invalid EXC_RETURN value.
	 *	19	The processor has attempted to access a coprocessor.
	 *	24	The processor has made an unaligned memory access.
	 *	25	The processor has executed an SDIV or UDIV instruction with a divisor of 0.
	 *
	 *	Not shown bits are Reserved!
	 */

/***********************************************************************************************************************************
 *	 enum name         : rtcBkpReg
 *
 *   enum Description  : enumeration of all months names
 *
 **********************************************************************************************************************************/
	enum monthNames
	{
		Januari = 1,
		Februari,
		March,
		April,
		May,
		June,
		Juli,
		August,
		September,
		October,
		November,
		December
	};

/***********************************************************************************************************************************
 *	enum name          : weekdays
 *
 *  enum Description   : enumeration of the weekday names
 *
 **********************************************************************************************************************************/
		enum class weekdays : uint8_t
		{
			SUNDAY = 0,
			MONDAY,
			TUESDAY,
			WEDNESDAY,
			THURSDAY,
			FRIDAY,
			SATURDAY
		};

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
 *	Class name         : rtc
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
class rtcTimer
{
    private:
		static inline dateTime toSet; //Variable which stores the time and date the rtcTimer needs to be set to.

		static inline RTC_HandleTypeDef hrtc; //HAL RTC handle typedef used to access the RTC via HAL

        static void setTime(const time &input); //Set the time into RTC registers.
        static void setDate(const date &input); //Set the date into RTC registers.


    public:
        /***********************************************************************************************************************************
         *  Method Name        : rtcTimer
         *
         *  Method Description : Construct a new rtc timer object
         *
         *  Entry              : None
         *
         *  Exit               : None
         *
         **********************************************************************************************************************************/
        rtcTimer(void) {}
//        static rtcTimer& getInstance(); //Get the instance of rtcTimer object.
        static void rtcInit(void); //Init the RTC timer settings via HAL
        static void setDateTime(void); //Set the date and time based on internal to_set variable.
        static void updateDateTime(const uint32_t &value); //Update the to_set value.
        static dateTime getDateTime(void); //Get the current date and time from the RTC registers
        static uint32_t readBackupRegister(const uint8_t &address); //Read a RTC backup register.
        static void writeBackupRegister(const uint8_t &address, const uint32_t &data); //Write a RTC backup register.
};

/***********************************************************************************************************************************
 *  Prototypes         :
 **********************************************************************************************************************************/
    
#endif	/* INC_RTC_RTC_HPP_ */

