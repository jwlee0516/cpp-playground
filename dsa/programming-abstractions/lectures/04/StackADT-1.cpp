/*
Stack Overview 

A stack is a LIFO (last-in, first-out) data structure. It generally supports a limited set of operations:

clear() : void	        removes all elements from the stack
equals(stack) : bool	returns true if the two stacks contain the same elements in the same order, false otherwise
isEmpty() : bool        returns true if the stack contains no elements, false otherwise
peek() : Type<T>        returns the element on the top of the stack without removing it
pop() : void            removes the element from the top of the stack and returns it
push(value)	: void      pushes value onto the stack
size() : int            returns the number of values in the stack

stack does not support a search operation or an operation to find and remove an element with a specific value.
*/

#include <iostream>
#include "console.h"
#include "stack.h"
using namespace std;

int main()
{
    Stack<int> s;

    s.push(10);
    s.push(20);
    s.push(15);
    s.push(12);

    while(!s.isEmpty())
    {
        cout << s.pop() << endl;
    }

    
    string str = "muffins";
    Stack<char> myStack;

    for (char ch: str)
    {
        myStack.push(ch);
    }
    
    while (!myStack.isEmpty())
    {
        cout << myStack.pop();
    }
    cout << endl;
    
    
    return 0;

}