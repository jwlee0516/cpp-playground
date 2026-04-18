/*

ADTS - a set of data structures that provide an agreed-upon model for how data is stored and manipulated

1. implementation details of an ADT might vary greatly from one language to another
2. there are many different ways to implement a particular ADT in any one language
    (a) have a common language for discussing solutions to a wide range of problems with other people in our field
    (b) write code that is fairly comprehensible even when viewed by someone who isn't familiar with the specifics of the language it's written in
    (c) focus on problem-solving without getting bogged down in unnecessary, low(ish)-level implementation details
Approach them from the client perspective. That is, we will act as consumers of ADTs that 
have been implemented for us in C++ with a focus on what those ADTs allow us to accomplish, 
without getting bogged down with the behind-the-scenes details of exactly how those ADTs are implemented.

The first ADT we explored was the Vector:

A vector is a type of list that expands and shrinks automatically as new elements are added or removed.
The elements in a vector are inherently ordered. Each element in a vector is assigned a position relative to the others.
The elements in a vector are indexed 0 through n - 1 (where n is the number of elements in the vector).
The vector is a homogenous container. All the elements in a given vector must be of the same type.

- Elements are stored in contiguous blocks in memory.
- We can quickly access the element at any given index in the the vector.

One place where you see a vector in action pretty much daily is if you open multiple tabs 
in your web browser. Tabs have an inherent ordering, and the size of the underlying data structure 
used to keep track of them can grow and shrink as you open and close more tabs.
*/

#include <iostream>
#include "console.h"
#include "vector.h"
using namespace std;

int main()
{
    Vector<int> v = {15, 20, 18};

    // A this point, we have:
    // +----+----+----+
    // | 15 | 20 | 18 |
    // +----+----+----+
    //   0    1    2

    // We have a size() function that tells us how many elements are in a vector,
    // and we can access individual elements using VARIABLE_NAME[INDEX]. Putting those
    // together, we can loop through the vector and print its contents:
    for (int i = 0; i < v.size(); i++)
    {
        cout << "index " << i << ": " << v[i] << endl; 
    }

    // We can also check whether a vector is empty using the isEmpty() function:
    if (v.isEmpty())
    {
        cout << "Empty vector. " << endl;
    }

    // The add() function adds an element to the end of the vector.
    v.add(33);

    // We now have:
    // +----+----+----+----+
    // | 15 | 20 | 18 | 33 |
    // +----+----+----+----+
    //   0    1    2    3

    // The insert() function adds an element at a given index, first scooting over
    // all elements at and to the right of that index in order to make room for the
    // new element.

    v.insert(2, 90);

    // We now have:
    // +----+----+----+----+----+
    // | 15 | 20 | 90 | 18 | 33 |
    // +----+----+----+----+----+
    //   0    1    2    3    4

    // The remove() function removes the element at a given index, then scoots over
    // all elements to the right of that index so as not to leave a gap in the vector.

    v.remove(0);

    // We now have:
    // +----+----+----+----+
    // | 20 | 90 | 18 | 33 |
    // +----+----+----+----+
    //   0    1    2    3

    return 0;
}