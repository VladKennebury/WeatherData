/*  ICT283 Assignment 2 - Data Structures and Abstractions
    Author: Vladislav Kennebury
    Date: 08/06/2020

    Class: Date header
    Description:
    Stores and sets values for day, month and year.
    Presents methods for obtaining private variables through
    the use of getters.

    Method and variable declarations.
*/

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
using namespace std;

    /**
	 * @class Date
	 * @brief  Stores values of date, including day, month and year
	 * Contains overloaded operators to allow comparisons of Date
	 *
	 * @author Vladislav Kennebury
	 * @version 02
	 * @date 08/06/2020
	 *
	 */

class Date
{
    public:

        /**
		 * @brief Constructor - Initialises all variables
		 *
		 * @return
		 */
        Date();

        /**
		 * @brief  Returns day
		 *
		 * @return day - integer
		 */
        int getDay();

        /**
		 * @brief  Sets the value of day
		 *
		 * @param d - passed integer value for day
		 * @return void
		 */
        void setDay(int d);

        /**
		 * @brief  Returns month
		 *
		 * @return month - integer
		 */
        int getMonth();

        /**
		 * @brief  Sets the value of month
		 *
		 * @param m - passed integer value for month
		 * @return void
		 */
        void setMonth(int m);

        /**
		 * @brief  Returns year
		 *
		 * @return year - integer
		 */
        int getYear();

        /**
		 * @brief  Sets the value of year
		 *
		 * @param y - passed integer value for year
		 * @return void
		 */
        void setYear(int y);

    private:
        ///Stores year
        int year;
        ///Stores month
        int month;
        ///Stores day
        int day;
};

#endif // DATE_H
