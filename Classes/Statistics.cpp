/*  ICT283 Assignment 2 - Data Structures and Abstractions
    Author: Vladislav Kennebury
    Date: 08/06/2020

    Class: Statistics implementation
    Description:
    Encapsulates values of into a STL Map. General methods
    allow the addition of new elements into the map, as well as overloaded
    operators which allows specific use, such as an out of
    bounds check and creating a deep copy of an object.

    Methods allow the calculation of sum, average and standard
    deviation of elements in the map.

    Method and variable implementation.
*/

#include "Statistics.h"
#include <map>
#include<assert.h>

Statistics::Statistics() //Constructor
{
    elements = 0; //Stores the number of elements in the map
    total = 0; //Stores sum of all elements
    average = 0; //Stores average of all elements
    standardDeviation = 0; //Stores standard deviation of all elements
}

Statistics::~Statistics() //Deconstructor
{
    mp.clear();
}

float& Statistics::operator[](const int key) //Overloaded [] operator for searching of specific elements
{
    assert(key >= 0 && key <= getElements());
    return mp[key];
}

void Statistics::add(float ele) //Adds new elements to the map
{
    mp.insert(pair<int, float>(elements, ele));
    elements++;
}

int Statistics::getElements()const
{
    return(mp.size());
}

float Statistics::getTotal()
{
    return total; //Returns total via getter method
}

void Statistics::setTotal() // Sets total
{
    for(int i = 0; i < getElements(); i++){ //Stores sum of all elements into total
        total += mp[i];
    }
}

float Statistics::getAverage()
{
    return average; //Returns average via getter method
}

void Statistics::setAverage() //Sets average
{
    if(getElements() != 0){ // Avoids divided by 0 error
        average = getTotal() / getElements(); //Stores sum/number of elements into average
    }
}

float Statistics::getDeviation()
{
    return standardDeviation; //Returns standard deviation via getter method
}

void Statistics::setDeviation() //Sets deviation
{
    for(int i = 0; i < getElements(); i++){
        standardDeviation += (mp[i] - average) * (mp[i] - average); // Stores (element - average)^2
    }
    standardDeviation = standardDeviation / (getElements() - 1); //Divides by the number of elements -1 for variance
    standardDeviation = sqrt(standardDeviation); //Square root of variance = standard deviation
}

void Statistics::clearMap() //Clears map for future input
{
    mp.clear();
    elements = 0;
    total = 0;
    average = 0;
    standardDeviation = 0;
}
