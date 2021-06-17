/*  ICT283 Assignment 2 - Data Structures and Abstractions
    Author: Vladislav Kennebury
    Date: 08/06/2020

    Class: Statistics header
    Description:
    Encapsulates values of into a STL Map. General methods
    allow the addition of new elements into the map, as well as overloaded
    operators which allows specific use, such as an out of
    bounds check and creating a deep copy of an object.

    Methods allow the calculation of sum, average and standard
    deviation of elements in the map.

    Method and variable declarations.
*/

#ifndef STATISTICS_H
#define STATISTICS_H

#include<iostream>
#include<string>
#include <cmath> //Math library to utilise square root
#include <map> //STL Map
using namespace std;

    /**
	 * @class Statistics
	 * @brief  Encapsulates a STL Map of type float, and performs
	 * mathematical calculations
	 *
	 * Input and output are handled in main. Statistics is responsible
	 * for storing and managing data. Functions are general to increase
	 * re-usability of code, taking into account various forms of data.
	 *
	 * Certain functions are able to calculate the total, average and
	 * standard deviation of the dynamic array.
	 *
	 * @author Vladislav Kennebury
	 * @version 02
	 * @date 08/06/2020
	 *
	 */

class Statistics
{
    public:

        /**
		 * @brief Constructor - Initialises all variables
		 *
		 * Sets initial values to variables
		 *
		 * @return
		 */
        Statistics();

        /**
		 * @brief  Deconstructor - Deletes map
		 *
		 * Frees memory after an map is used
		 *
		 * @return
		 */
        ~Statistics();

        /**
		 * @brief  Returns total
		 *
		 * @return total - float
		 */
        float getTotal();

        /**
		 * @brief  Sets the value of total
		 *
		 * Adds all the elements within the map for the sum
		 *
		 * @return void
		 */
        void setTotal();

        /**
		 * @brief  Returns average
		 *
		 * @return average - float
		 */
        float getAverage();

        /**
		 * @brief  Sets the value of average
		 *
		 * Divides total by elements
		 * (Number of elements within the map)
		 *
		 * @return void
		 */
        void setAverage();

        /**
		 * @brief  Returns deviation
		 *
		 * @return standardDeviation - float
		 */
        float getDeviation();

        /**
		 * @brief  Sets the value of standardDeviation
		 *
		 * Stores (element - average)^2
		 * Divides by the number of elements -1 for variance
		 * Square root of variance = standard deviation
		 *
		 * @return void
		 */
        void setDeviation();

        /**
		 * @brief Add - Places new element within the map
		 *
		 * Inserts value into map with associated key
		 *
		 * @param ele - Element input of type float
		 * @return void
		 */
        void add(float ele);

        /**
		 * @brief operator[] - Overloaded [] operator
		 *
		 * Returns the value of specified index, as well as
		 * checking for out of bounds in the search
		 *
		 * @param key - specified index of element in map
		 * @return mp[element] - element in map at index
		 */
        float& operator[] (const int key);

        /**
		 * @brief  Returns elements
		 *
		 * @return elements - int
		 */
        int getElements()const;

        /**
		 * @brief clearMap - Clears all elements within map
		 * Allows future use in other classes
		 *
		 * @return void
		 */
        void clearMap();

    private:
        /// STL Map of type float
        map<int, float> mp;
        /// Number of elements in the Map
        int elements;
        /// Sum of all elements
        float total;
        /// Average of all elements
        float average;
        ///Standard deviation of all elements
        float standardDeviation;
};

#endif // STATISTICS_H
