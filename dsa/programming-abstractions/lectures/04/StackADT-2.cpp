// Vectors as Stacks (and a Note About the Power of Abstraction!)

#include <iostream>
#include "console.h"
#include "stack.h"
#include "vector.h"
using namespace std;


int main()
{
    // Stack approach
    Stack<int> s;

    s.push(10);
    s.push(20);
    s.push(15);

    cout << s.pop() << endl;
    cout << "Stack contents: " << s << endl;


    // Vector approach
    Vector<int> v;

    v.add(10);
    v.add(20);
    v.add(15);

    cout << v.remove(v.size() - 1) << endl;
    cout << "Vector contents: " << v << endl;

    return 0;
}

/*
The stack version is not only easier to read, but also less error prone. There is less code to parse 
(we can infer its semantics with a quick glance at the operations being performed), and we don't 
have to stop to consider whether we're pushing and popping at the correct index.

With the vector approach, we might have to stop to consider the relationship between v.add() and 
v.remove(v.size() - 1) to ensure we understand what the code is doing. Someone coding this up with 
vectors could also easily remove elements from the wrong end of the vector or have an off-by-one error 
that causes us to go out of bounds. Those problems simply don't exist with the stack approach, where the 
details of the s.push() and s.pop() operations are abstracted away from us and we can assume they work as intended.
*/