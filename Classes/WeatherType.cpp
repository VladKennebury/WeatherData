/*  ICT283 Assignment 2 - Data Structures and Abstractions
    Author: Vladislav Kennebury
    Date: 08/06/2020

    Class: WeatherType implementation
    Description: Stores and sets values specific to Weather, as
    well as overloading operator functions that are required for
    comparison of WeatherType objects.

    Method and variable implementation.
*/

#include "WeatherType.h"

WeatherType::WeatherType()
{
    //Initialises variables
    speed = 0;
    temperature = 0;
    radiation = 0;
}

//Setters and getters
void WeatherType::setDate(Date d)
{
    //Sets year, month and day
    calendar.setYear(d.getYear());
    calendar.setMonth(d.getMonth());
    calendar.setDay(d.getDay());
}

Date WeatherType::getDate()
{
    return(calendar);
}

int WeatherType::getDateYear()
{
    return(calendar.getYear());
}

int WeatherType::getDateMonth()
{
    return(calendar.getMonth());
}

int WeatherType::getDateDay()
{
    return(calendar.getDay());
}

void WeatherType::setTime(Time t)
{
    //Sets hours, minutes and seconds
    clock.setHours(t.getHours());
    clock.setMinutes(t.getMinutes());
    clock.setSeconds(t.getSeconds());
}

Time WeatherType::getTime()
{
    return(clock);
}

int WeatherType::getTimeHours()
{
    return(clock.getHours());
}

int WeatherType::getTimeMinutes()
{
    return(clock.getMinutes());
}

int WeatherType::getTimeSeconds()
{
    return(clock.getSeconds());
}

void WeatherType::setSpeed(float s)
{
    speed = s;
}

float WeatherType::getSpeed()
{
    return(speed);
}

void WeatherType::setTemperature(float t)
{
    temperature = t;
}

float WeatherType::getTemperature()
{
    return(temperature);
}

void WeatherType::setRadiation(float r)
{
    radiation = r;
}

float WeatherType::getRadiation()
{
    return(radiation);
}

//Overloaded operators all compare year, month, day, hours, minutes. Return boolean...
// based upon the result of comparisons. Checks larger values first, as if an object has...
// the same time but differs by years, there is no reason to check any other variables after year.
bool WeatherType::operator==(WeatherType& otherW)
{
    return((calendar.getYear() == otherW.calendar.getYear()) && (calendar.getMonth() == otherW.calendar.getMonth())
           && (calendar.getDay() == otherW.calendar.getDay()) && (clock.getHours() == otherW.clock.getHours()) &&
           (clock.getMinutes() == otherW.clock.getMinutes()));
}

bool WeatherType::operator!=(WeatherType& otherW)
{
    return(calendar.getYear() != otherW.calendar.getYear() || calendar.getMonth() != otherW.calendar.getMonth()
           || calendar.getDay() != otherW.calendar.getDay() || clock.getHours() != otherW.clock.getHours() ||
           clock.getMinutes() != otherW.clock.getMinutes());
}

bool WeatherType::operator>=(WeatherType& otherW)
{
    return((calendar.getYear() > otherW.calendar.getYear()) || (calendar.getYear() == otherW.calendar.getYear() &&
           calendar.getMonth() > otherW.calendar.getMonth()) || (calendar.getYear() == otherW.calendar.getYear() &&
            calendar.getMonth() == otherW.calendar.getMonth() && calendar.getDay() > otherW.calendar.getDay()) ||
           (calendar.getYear() == otherW.calendar.getYear() && calendar.getMonth() == otherW.calendar.getMonth() &&
            calendar.getDay() == otherW.calendar.getDay() && clock.getHours() > otherW.clock.getHours()) ||
            (calendar.getYear() == otherW.calendar.getYear() && calendar.getMonth() == otherW.calendar.getMonth() &&
            calendar.getDay() == otherW.calendar.getDay() && clock.getHours() == otherW.clock.getHours() &&
             clock.getMinutes() >= otherW.clock.getMinutes()));
}

bool WeatherType::operator>(WeatherType& otherW)
{
    return((calendar.getYear() > otherW.calendar.getYear()) || (calendar.getYear() == otherW.calendar.getYear() &&
           calendar.getMonth() > otherW.calendar.getMonth()) || (calendar.getYear() == otherW.calendar.getYear() &&
            calendar.getMonth() == otherW.calendar.getMonth() && calendar.getDay() > otherW.calendar.getDay()) ||
           (calendar.getYear() == otherW.calendar.getYear() && calendar.getMonth() == otherW.calendar.getMonth() &&
            calendar.getDay() == otherW.calendar.getDay() && clock.getHours() > otherW.clock.getHours()) ||
            (calendar.getYear() == otherW.calendar.getYear() && calendar.getMonth() == otherW.calendar.getMonth() &&
            calendar.getDay() == otherW.calendar.getDay() && clock.getHours() == otherW.clock.getHours() &&
             clock.getMinutes() > otherW.clock.getMinutes()));
}

bool WeatherType::operator<=(WeatherType& otherW)
{
    return((calendar.getYear() < otherW.calendar.getYear()) || (calendar.getYear() == otherW.calendar.getYear() &&
           calendar.getMonth() < otherW.calendar.getMonth()) || (calendar.getYear() == otherW.calendar.getYear() &&
            calendar.getMonth() == otherW.calendar.getMonth() && calendar.getDay() < otherW.calendar.getDay()) ||
           (calendar.getYear() == otherW.calendar.getYear() && calendar.getMonth() == otherW.calendar.getMonth() &&
            calendar.getDay() == otherW.calendar.getDay() && clock.getHours() < otherW.clock.getHours()) ||
            (calendar.getYear() == otherW.calendar.getYear() && calendar.getMonth() == otherW.calendar.getMonth() &&
            calendar.getDay() == otherW.calendar.getDay() && clock.getHours() == otherW.clock.getHours() &&
             clock.getMinutes() <= otherW.clock.getMinutes()));
}

bool WeatherType::operator<(WeatherType& otherW)
{
    return((calendar.getYear() < otherW.calendar.getYear()) || (calendar.getYear() == otherW.calendar.getYear() &&
           calendar.getMonth() < otherW.calendar.getMonth()) || (calendar.getYear() == otherW.calendar.getYear() &&
            calendar.getMonth() == otherW.calendar.getMonth() && calendar.getDay() < otherW.calendar.getDay()) ||
           (calendar.getYear() == otherW.calendar.getYear() && calendar.getMonth() == otherW.calendar.getMonth() &&
            calendar.getDay() == otherW.calendar.getDay() && clock.getHours() < otherW.clock.getHours()) ||
            (calendar.getYear() == otherW.calendar.getYear() && calendar.getMonth() == otherW.calendar.getMonth() &&
            calendar.getDay() == otherW.calendar.getDay() && clock.getHours() == otherW.clock.getHours() &&
             clock.getMinutes() < otherW.clock.getMinutes()));
}
