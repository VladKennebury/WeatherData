/*  ICT283 Assignment 2 - Data Structures and Abstractions
    Author: Vladislav Kennebury
    Date: 08/06/2020

    Class: Time implementation
    Description:
    Stores  and sets values for hours, minutes, seconds and type.
    Presents methods for obtaining private variables through
    the use of getters.

    Method and variable implementation.

*/

#include "Time.h"

Time::Time() //Constructor initialisation
{
    hours = 0; //Stores hours
    minutes = 0; //Stores minutes
    seconds = 0; //Stores seconds
}

void Time::setHours(int h) //Sets hours with passed h parameter
{
    if(h >= 0 && h < 24){ //Checks if the passed hour is between 0 and 24
        hours = h;
    }
    else{
        hours = 0; //Sets value to 0 is h is outside ranges for input check
    }
}

int Time::getHours()
{
    return hours; //Returns hours via getter method
}

void Time::setMinutes(int m) //Sets minutes with passed m parameter
{
    if(m >= 0 && m < 60){ //Checks if passed minutes are between 0 and 60
        minutes = m;
    }
    else{
        minutes = 0; //Sets value to 0 if validity check fails
    }
}

int Time::getMinutes()
{
    return minutes; //Returns minute via getter method
}

void Time::setSeconds(int s) //Sets seconds with passed s parameter
{
    if(s >= 0 && s < 60){ //Checks if pass seconds are between 0 and 60
        seconds = s;
    }
    else{
        seconds = 0; //Sets value to 0 if validity check fails
    }
}

int Time::getSeconds()
{
    return seconds; //Returns seconds via getter method
}
