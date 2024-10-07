/***********************************************************************************************************************************
 *  File name          : rtc.cpp
 *  Author             : GGT Nesselaar
 *
 *  Compiler           : STM32CubeIDE
 *  Manufacturer       : STMicroelectronics
 *  CreationDate       : Nov 29, 2023
 *
 *  File Description   : 
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *  Used Defines       : 
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *  Used Includes      : 
 **********************************************************************************************************************************/
#include "rtc.hpp"

/***********************************************************************************************************************************
 *  Used Prototypes    :
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *  Method Name        : getInstance
 *
 *  Method Description : Get the instance of RTC object.
 *
 *  Entry              : None
 *
 *  Exit               : RTC_timer&, Reference to RTC_timer object.
 *
 **********************************************************************************************************************************/
/*rtcTimer& rtcTimer::getInstance()
{
    static rtcTimer Rtc;
    return Rtc;
}*/

/***********************************************************************************************************************************
 *  Method Name        : setTime
 *
 *  Method Description : Set the time into RTC registers.
 *
 *  Entry              : input Time, struct with the time to set the RTC to.
 *
 *  Exit               : None
 *
 **********************************************************************************************************************************/
void rtcTimer::setTime(const time &input)
{
    RTC_TimeTypeDef sTime = { 0 };
    sTime.Hours = input.hours;
    sTime.Minutes = input.minutes;
    sTime.Seconds = input.seconds;
    sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
    sTime.StoreOperation = RTC_STOREOPERATION_RESET;
    if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK)
    {
        Error_Handler();
    }
}

/***********************************************************************************************************************************
 *  Method Name        : setDate
 *
 *  Method Description : Set the date into RTC registers.
 *
 *  Entry              : input Date, struct with the time to set the RTC to.
 *
 *  Exit               : None
 *
 **********************************************************************************************************************************/
void rtcTimer::setDate(const date &input)
{
    RTC_DateTypeDef sDate = { 0 };
    sDate.Month = input.month;
    sDate.Date = input.day;
    sDate.Year = input.year - startYear;

    if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN) != HAL_OK)
    {
        Error_Handler();
    }
}

/***********************************************************************************************************************************
 *  Method Name        : rtcInit
 *
 *  Method Description : Init the RTC timer settings via HAL
 *
 *  Entry              : None
 *
 *  Exit               : None
 *
 **********************************************************************************************************************************/
void rtcTimer::rtcInit(void)
{
    __HAL_RCC_RTC_ENABLE();

    hrtc.Instance = RTC;
    hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
    hrtc.Init.AsynchPrediv = 127; //127 for hse_div30 and LSE
    hrtc.Init.SynchPrediv = 255; // 6249 for hse_div30 255 for LSE
    hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
    hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
    hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
    //if((RCC->BDCR & RCC_BDCR_RTCEN) == 0){ //only init if not inited (only when vbat)
    if (HAL_RTC_Init(&hrtc) != HAL_OK) 
    {
        Error_Handler();
    }
    //}
}

/***********************************************************************************************************************************
 *  Method Name        : setDateTime
 *
 *  Method Description : Set the date and time based on internal to_set variable.
 *
 *  Entry              : None
 *
 *  Exit               : None
 *
 **********************************************************************************************************************************/
void rtcTimer::setDateTime()
{
    setTime(toSet.t);
    setDate(toSet.d);
}

/***********************************************************************************************************************************
 *  Method Name        : updateDateTime
 *
 *  Method Description : Update the to_set value.
 *
 *  Entry              : value, The new value to set the RTC to (in compressed uint32_t format)
 *
 *  Exit               : None
 *
 **********************************************************************************************************************************/
void rtcTimer::updateDateTime(const uint32_t &value)
{
    auto newDateTime = dateTime(value, 0);
    toSet = newDateTime;
}

/***********************************************************************************************************************************
 *  Method Name        : getDateTime
 *
 *  Method Description : Get the current date and time from the RTC registers
 *
 *  Entry              : None
 *
 *  Exit               : DateTime
 *
 **********************************************************************************************************************************/
dateTime rtcTimer::getDateTime()
{
    RTC_TimeTypeDef RTCTime = { 0 };
    RTC_DateTypeDef RTCDate = { 0 };

    HAL_RTC_GetTime(&hrtc, &RTCTime, RTC_FORMAT_BIN);
    HAL_RTC_GetDate(&hrtc, &RTCDate, RTC_FORMAT_BIN);

    time outputTime = time(RTCTime.Hours, RTCTime.Minutes, RTCTime.Seconds, (100 - ((float) RTCTime.SubSeconds / (float) RTCTime.SecondFraction) * 100));
    outputTime.milliseconds *= 10;
    if (outputTime.milliseconds >= 1000)
    {
        outputTime.seconds += 1;
        outputTime.milliseconds = 0;
    }
    date outputDate = date(RTCDate.Year + startYear, RTCDate.Month, RTCDate.Date);

    return dateTime(outputDate, outputTime);
}

/***********************************************************************************************************************************
 *  Method Name        : readBackupRegister
 *
 *  Method Description : Read a RTC backup register.
 *
 *  Entry              : address, The address of the register to read (between 0-19 for F4 and 0-31 for F7)
 *
 *  Exit               : uint32_t, The contents of the backup register.
 *
 **********************************************************************************************************************************/
uint32_t rtcTimer::readBackupRegister(const uint8_t &address)
{
    //check address if not correct just return max value of uint32_t
    if (address > RTC_BKP_DR31) 
    {
        return UINT32_MAX;
    }
    return HAL_RTCEx_BKUPRead(&hrtc, address);
}

/***********************************************************************************************************************************
 *  Method Name        : writeBackupRegister
 *
 *  Method Description : Write a RTC backup register.
 *
 *  Entry              : address, The address of the register to read (between 0-19 for F4 and 0-31 for F7)
 *                       data, The data to write to the register.
 *
 *  Exit               : None
 *
 **********************************************************************************************************************************/
void rtcTimer::writeBackupRegister(const uint8_t &address, const uint32_t &data)
{
    if (address < RTC_BKP_DR31)
    {
        HAL_RTCEx_BKUPWrite(&hrtc, address, data);
    }
}

