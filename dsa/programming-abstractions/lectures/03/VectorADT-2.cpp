/*

Runtime Comparison: add(value) vs. insert(0, value)

Inserting at the beginning of a vector with v.insert(0, value) forces us to spend time 
scooting over every single element that the vector already contains. Repeatedly inserting 
at the beginning of a vector, then, is dangerously slow. Each new insertion must perform 
more work than the last, because there is one more element to scoot over each time.

The v.add(value) function is, in comparison, quite fast. It just plunks a new element 
onto the end of the vector. This occasionally causes the vector to quietly expand.

*/

#include <iostream>
#include "console.h"
#include "SimpleTest.h"
#include "vector.h"
using namespace std;

void vectorAdd(int size)
{
    Vector<int> v;

    for(int i = 0; i < size; i++)
    {
        v.add(i);
    }
}

void vectorInsert(int size)
{
    Vector<int> v;
    
    for(int i = 0; i < size; i++)
    {
        v.insert(0, i);
    }
}

PROVIDED_TEST("runtime comparison")
{
    int size = 500000;

    TIME_OPERATION(size, vectorAdd(size));
    TIME_OPERATION(size, vectorInsert(size));
}

int main()
{
    runSimpleTests(ALL_TESTS);
    return 0;
}

// size	    vectorAdd() runtime	  vectorInsert() runtime  how much slower?
// 50,000	      0.005s	            0.086s	              17.2x
// 500,000	      0.029s	            9.794s	              337.8x
