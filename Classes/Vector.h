/*  ICT283 Assignment 2 - Data Structures and Abstractions
    Author: Vladislav Kennebury
    Date: 08/06/2020

    Template Class: Vector header
    Description:
    Encapsulates values of type T into a dynamic array. General methods
    allow the addition of new elements into the array, as well as
    doubling the capacity of the array to allow more elements to be
    stored. Overloaded operators allow specific use, such as out of
    bounds checking and use of creating a deep copy of an object.

    Method and variable declarations and implementation.
*/

#ifndef VECTOR_H
#define VECTOR_H

#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

	/**
	 * @class Vector
	 * @brief  Template class which encapsulates a dynamic array of type T
	 *
	 * Input and output are handled in main. Vector is responsible
	 * for storing and managing data. Functions are general to increase
	 * re-usability of code, taking into account various forms of data.
	 *
	 * @author Vladislav Kennebury
	 * @version 02
	 * @date 08/06/2020
	 *
	 */

template<class T>
class Vector
{
    public:

		/**
		 * @brief Constructor - Initialises all variables
		 *
		 * Sets initial values to variables and creates new dynamic array
		 *
		 * @return
		 */
        Vector();

        /**
		 * @brief  Copy Constructor - Copies all variables for a new object
		 *
		 * Sets initial values to variables and creates new dynamic array for object
		 *
		 * @param object - Vector<T> object which will be copied
		 * @return
		 */
        Vector(const Vector<T>& object);

        /**
		 * @brief  Deconstructor - Deletes array
		 *
		 * Frees memory after an array is used
		 *
		 * @return
		 */
        ~Vector();

        /**
		 * @brief  Expand - Doubles the capacity of the dynamic array
		 *
		 * Copies elements over, and increases the capacity of the array
		 * in order to make more room for additional elements
		 *
		 * @return void
		 */
        void expand();

        /**
		 * @brief Add - Places new element within the array
		 *
		 * Expand is called if the number of elements exceeds
		 * the capacity, else the new elements is added.
		 *
		 * @param ele - Element input of type T
		 * @return void
		 */
        void add(T ele);

        /**
		 * @brief Add - Places new element within the array at specified index
		 *
		 * Expand is called if the number of elements exceeds
		 * the capacity, else the new elements is added.
		 * Adds to the vector at requested index
		 *
		 * @param ele - Element input of type T
		 * @param e - Specified index of type int
		 * @return void
		 */
        void add(T ele, int e);

        /**
		 * @brief operator[] - Overloaded [] operator
		 *
		 * Returns the value of specified index, as well as
		 * checking for out of bounds in the search
		 *
		 * @param index - specified index of element in array
		 * @return arr[element] - element in array at index
		 */
        T& operator[](const int index);

        /**
		 * @brief operator= - Overloaded assignment operator
		 *
		 * Creates a deep copy of an object, which allows either object
		 * to change value without affecting the value of the other
		 * object. Thus, not allowing a shallow copy where pointers
		 * are pointing to the same memory address
		 *
		 * @param other - Vector<T> reference object
		 * @return Vector<T>& - reference to vector object of type T
		 */
        Vector<T>& operator=(const Vector<T>& other);

        /**
		 * @brief  Returns number of elements in the array
		 *
		 * @return elements - integer
		 */
        int getElements()const;

        /**
		 * @brief  Returns the array capacity
		 *
		 * @return arrSize - integer
		 */
        int getArrSize()const;

    private:
        /// Pointer to dynamic array of type T
        T *arr;
        /// Number of elements in the array
        int elements;
        /// Capacity of array
        int arrSize;
};

template<class T>
Vector<T>::Vector() //Constructor
{
    arrSize = 200; //Stores array capacity, with initial value of 200
    elements = 0; //Stores the number of elements in the array
    arr = new T[arrSize]; // Dynamic array declaration of type T
}

template<class T>
Vector<T>::~Vector() //Deconstructor
{
    delete[]arr; //Frees memory after arr is deleted
}

template<class T>
void Vector<T>::expand() //Increases the capacity of the array
{
    arrSize *= 2; //Doubles the capacity

    T *tempArr = new T[arrSize]; //Creates a new temporary array

    for(int i = 0; i < elements; i++){ //Copies elements of original to temp array
        tempArr[i] = arr[i];
    }

    delete[]arr; //Deletes original array

    arr = tempArr; //Copies temp array to the current array. Therefore, increasing the size but maintaining the elements

}

template<class T>
T& Vector<T>::operator[](const int index) //Overloaded [] operator for searching of specific elements
{
    assert(index >= 0 && index <= arrSize);
    return arr[index];
}

template<class T>
Vector<T>::Vector(const Vector<T>& object) //Copy Constructor which assigns an object to another, if one does not exist
{
    elements = object.elements;
    arrSize = object.arrSize;
    //Copies all variables and elements form object 1 to object 2
    for(int i = 0; i < elements; i++){
        arr[i] = object.arr[i];
    }
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) //Overloaded assignment operator (=)
{
    if(this != &other){ //Checks to make sure it's not the same object
        delete[] arr; //Deletes array
        arrSize = other.arrSize; //Copies capacity and number of elements
        elements = other.elements;
        arr = new T[arrSize]; //Declares new array

        for(int i = 0; i < elements; i++){ //Copies all elements from the array to new object array
            arr[i] = other.arr[i];
        }
    }
    return *this; //Important for creating a deep copy of an object
}

template<class T>
void Vector<T>::add(T ele) //Adds new elements to the dynamic array
{
    if(elements >= arrSize){ //Checks if capacity allows the addition of an element
        expand(); //Increases capacity if full
    }

    arr[elements++] = ele; //Adds element to at additional index
}

template<class T>
void Vector<T>::add(T ele, int e) //Adds new elements to the dynamic array
{
    if(e >= arrSize){ //Checks if capacity allows the addition of an element
        expand(); //Increases capacity if full
    }

    arr[e] = ele; //Adds element to at additional index
    elements++;
}

template<class T>
int Vector<T>::getElements()const
{
    return elements; //Returns elements via getter method
}

template<class T>
int Vector<T>::getArrSize()const
{
    return arrSize; //Returns capacity via getter method
}

#endif // VECTOR_H
