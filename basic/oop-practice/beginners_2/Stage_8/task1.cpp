/*
Problem 1: stream insertion, overloading extraction (<< , >>) and subscript [] operators

This C++ program defines a class called 'BiggerInt' that represents a dynamic array of integers.
The class has private data members 'big_int_' and 'int_length_' to store the array and its size,
respectively. The class provides a default constructor to initialize the array as nullptr and size to zero,
an overloaded constructor to allow the creation of an array with specified values, and a copy constructor
to create a new 'BiggerInt' object with the same data as an existing object. The destructor is implemented to
release the dynamically allocated memory when the object is destroyed.

The class supports various operations, including assignment, pre-increment, post-increment, pre-decrement,
and post-decrement using overloaded operators. It also provides getter and setter functions for the array and its size,
as well as an overloaded '[]' operator for element access.

In the 'main' function, the program demonstrates the use of the 'BiggerInt' class by creating two 'BiggerInt'
objects, 'e1' and 'e2', and initializing them with different arrays. It then performs pre-increment and post-increment
operations on the arrays using the overloaded operators and displays the results. Similarly, it demonstrates pre-decrement
and post-decrement operations and their corresponding results. The program finally prints the modified arrays after
the increment and decrement operations.
*/

#include <iostream>
using namespace std;

class BiggerInt {

    
}