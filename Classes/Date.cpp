/*  ICT283 Assignment 2 - Data Structures and Abstractions
    Author: Vladislav Kennebury
    Date: 08/06/2020

    Class: Date implementation
    Description:
    Stores and sets values for day, month and year.
    Presents methods for obtaining private variables through
    the use of getters.

    Method and variable implementation.
*/

#include "Date.h"

Date::Date() //Constructor initialisation
{
    day = 0; //Stores day
    month = 0; //Stores month
    year = 0; //Stores year
}

int Date::getDay()
{
    return day; //Returns day via getter method
}

void Date::setDay(int d) //Sets value for day
{
    if(d > 31 || d < 1){ //Checks validity for day
        day = 0;
    }
    else{
        day = d;
    }
}

int Date::getMonth()
{
    return month; //Returns month via getter method
}

void Date::setMonth(int m) //Sets value for month
{
    if(m > 12 || m < 1){ //Checks validity for month
        month = 0;
       }
    else{
        month = m;
    }
}

int Date::getYear()
{
    return year; //Returns year via getter method
}

void Date::setYear(int y) //Sets value for year
{
    if(y < 0){ //Checks validity for year
        year = 0;
    }
    else{
        year = y;
    }
}
