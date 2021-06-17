/*  ICT283 Assignment 2 - Data Structures and Abstractions
    Author: Vladislav Kennebury
    Date: 08/06/2020

    Class: Time header
    Description:
    Stores  and sets values for hours, minutes, seconds and type.
    Presents methods for obtaining private variables through
    the use of getters.

    Method and variable declarations.
*/

#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <string>
using namespace std;

    /**
	 * @class Time
	 * @brief  Stores values of time, including hours and minutes,
	 *
	 * @author Vladislav Kennebury
	 * @version 02
	 * @date 08/06/2020
	 *
	 */

class Time
{
    public:

        /**
		 * @brief Constructor - Initialises all variables
		 *
		 * @return
		 */
        Time();

        /**
		 * @brief  Sets the value of hours
		 *
		 * @param h - passed integer value for hours
		 * @return void
		 */
        void setHours(int h);

        /**
		 * @brief  Returns hours
		 *
		 * @return hours - integer
		 */
        int getHours();

        /**
		 * @brief  Sets the value of minutes
		 *
		 * @param m - passed integer value for minutes
		 * @return void
		 */
        void setMinutes(int m);

        /**
		 * @brief  Returns minutes
		 *
		 * @return minutes - integer
		 */
        int getMinutes();

        /**
		 * @brief  Sets the value of seconds
		 *
		 * @param h - passed integer value for seconds
		 * @return void
		 */
        void setSeconds(int s);

        /**
		 * @brief  Returns seconds
		 *
		 * @return seconds - integer
		 */
        int getSeconds();

    private:
        ///Number of hours
        int hours;
        ///Number of minutes
        int minutes;
        ///Number of seconds
        int seconds;

};

#endif // TIME_H
