/*  ICT283 Assignment 2 - Data Structures and Abstractions
    Author: Vladislav Kennebury
    Date: 08/06/2020

    Class: WeatherType header
    Description: Stores and sets values specific to Weather, as
    well as overloading operator functions that are required for
    comparison of WeatherType objects.

    Method and variable declaration.
*/

#ifndef WEATHERTYPE_H
#define WEATHERTYPE_H

#include <iostream>
#include "time.h"
#include "date.h"
using namespace std;

    /**
	 * @class WeatherType
	 * @brief Stores and sets values specific to Weather.
	 * Overloaded operator functions are required for
	 * comparison of WeatherType objects.
	 *
	 * @author Vladislav Kennebury
	 * @version 01
	 * @date 08/06/2020
	 *
	 */

class WeatherType
{
    public:

        /**
		 * @brief Constructor - Initialises all variables
		 *
		 * Sets initial values to variables
		 *
		 * @return
		 */
        WeatherType();

        /**
		 * @brief  Sets the values of Date
		 *
		 * Sets the year, month and day for a specific date
		 *
		 * @param d - Date object
		 * @return void
		 */
        void setDate(Date d);

        /**
		 * @brief  Returns Date
		 *
		 * @return Date
		 */
        Date getDate();

        /**
		 * @brief  Returns year of date object - calendar
		 *
		 * @return int - calendar year
		 */
        int getDateYear();

        /**
		 * @brief  Returns month of date object - calendar
		 *
		 * @return int - calendar month
		 */
        int getDateMonth();

        /**
		 * @brief  Returns day of date object - calendar
		 *
		 * @return int - calendar day
		 */
        int getDateDay();

        /**
		 * @brief  Sets the values of Time
		 *
		 * Sets the hours, minutes and seconds for a specific time
		 *
		 * @param t - Time object
		 * @return void
		 */
        void setTime(Time t);

        /**
		 * @brief  Returns Time
		 *
		 * @return Time
		 */
        Time getTime();

        /**
		 * @brief  Returns hours of time object - clock
		 *
		 * @return int - clock hours
		 */
        int getTimeHours();

        /**
		 * @brief  Returns minutes of time object - clock
		 *
		 * @return int - clock minutes
		 */
        int getTimeMinutes();

        /**
		 * @brief  Returns seconds of time object - clock
		 *
		 * @return int - clock seconds
		 */
        int getTimeSeconds();

        /**
		 * @brief  Sets the value of speed
		 * Sets wind speed in m/s
		 *
		 * @param s - float
		 * @return void
		 */
        void setSpeed(float s);

        /**
		 * @brief  Returns speed
		 *
		 * @return speed - float
		 */
        float getSpeed();

        /**
		 * @brief  Sets the value of temperature
		 * Sets ambient air temperature in degrees Celsius
		 *
		 * @param t - float
		 * @return void
		 */
        void setTemperature(float t);

        /**
		 * @brief  Returns temperature
		 *
		 * @return temperature - float
		 */
        float getTemperature();

        /**
		 * @brief  Sets the value of radiation
		 * Sets solar radiation in W/m^2
		 *
		 * @param r - float
		 * @return void
		 */
        void setRadiation(float r);

        /**
		 * @brief  Returns radiation
		 *
		 * @return radiation - float
		 */
        float getRadiation();

        /**
		 * @brief operator== - Overloaded == operator
		 *
		 * Overloads operator to allow for comparisons between
		 * weatherType objects. Uses all date and time variables
		 * for comparison.
		 *
		 * @param otherW = WeatherType reference
		 * @return bool
		 */
        bool operator==(WeatherType& otherW);

        /**
		 * @brief operator!= - Overloaded != operator
		 *
		 * Overloads operator to allow for comparisons between
		 * weatherType objects. Uses all date and time variables
		 * for comparison.
		 *
		 * @param otherW = WeatherType reference
		 * @return bool
		 */
        bool operator!=(WeatherType& otherW);

        /**
		 * @brief operator>= - Overloaded >= operator
		 *
		 * Overloads operator to allow for comparisons between
		 * weatherType objects. Uses all date and time variables
		 * for comparison.
		 *
		 * @param otherW = WeatherType reference
		 * @return bool
		 */
        bool operator>=(WeatherType& otherW);

        /**
		 * @brief operator> - Overloaded > operator
		 *
		 * Overloads operator to allow for comparisons between
		 * weatherType objects. Uses all date and time variables
		 * for comparison.
		 *
		 * @param otherW = WeatherType reference
		 * @return bool
		 */
        bool operator>(WeatherType& otherW);

        /**
		 * @brief operator<= - Overloaded <= operator
		 *
		 * Overloads operator to allow for comparisons between
		 * weatherType objects. Uses all date and time variables
		 * for comparison.
		 *
		 * @param otherW = WeatherType reference
		 * @return bool
		 */
        bool operator<=(WeatherType& otherW);

        /**
		 * @brief operator< - Overloaded < operator
		 *
		 * Overloads operator to allow for comparisons between
		 * weatherType objects. Uses all date and time variables
		 * for comparison.
		 *
		 * @param otherW = WeatherType reference
		 * @return bool
		 */
        bool operator<(WeatherType& otherW);

    private:
        ///Stores date in Date Class
        Date calendar;
        ///Stores time in Time class
        Time clock;
        ///Stores wind speed in m/s
        float speed;
        ///Stores ambient air temperature in degrees Celsius
        float temperature;
        ///Stores solar radiation in W/m^2
        float radiation;
};

#endif // WEATHERTYPE_H
