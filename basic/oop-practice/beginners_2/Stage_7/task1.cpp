/*
Task description
This C++ program defines a class 'ComplexNumber' to represent complex numbers with real and imaginary parts.
The class provides member functions for arithmetic operations and comparisons on complex numbers.

Class 'ComplexNumber':
    - Private data members: 'real' (integer) and 'imaginary' (integer) to store the real and imaginary parts of the complex number.
    - Static data member 'count' (integer) to count the total number of 'ComplexNumber' objects created.

Public member functions:
    - Constructor 'ComplexNumber(int real = 0, int imaginary = 0)': Creates a complex number with default values.
    - Copy constructor 'ComplexNumber(const ComplexNumber& other)': Creates a deep copy of another complex number.
    - Destructor '~ComplexNumber()': Does nothing.

    - 'Input()': Allows user input for the real and imaginary parts of the complex number.
    - 'Output()': Displays the complex number in the form 'a+bi'.
    - 'countDisplay()': Returns the total number of 'ComplexNumber' objects created.

    - 'IsEqual(const ComplexNumber& other)': Checks if two complex numbers are equal.
    - 'Conjugate()': Calculates the conjugate of the complex number.

    - Operators: '+' (addition), '-' (subtraction), '*' (multiplication), '++' (pre-increment), '--' (pre-decrement),
    '++(int)' (post-increment), '--(int)' (post-decrement), '>=' (greater than or equal to), '<=' (less than or equal to),
    '==' (equal to), '!=' (not equal to).

In the 'main' function:
- Demonstrates operations on 'ComplexNumber' objects, such as addition, subtraction, and comparison.

Topics to learn:
This pointer
Operator overloading / Binary operator overloading / Unary operator overloading
Operator overloading as member functions / non-member functions / friend functions.
Static data member and Static function
*/

#include <iostream>
using namespace std;

class ComplexNumber {
    
}