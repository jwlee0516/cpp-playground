/*
Break Statements

A break statement causes us to leave whatever loop it resides in. A common idiom is to use a break statement 
to put an end to an otherwise infinite loop (such as a while (true) loop), although these can be used to 
terminate what would otherwise still be a non-infinite loop, as well. When we execute a break statement, 
our program jumps to the line immediately following whatever loop it resides within.
*/

#include <iostream>
#include "console.h"
#include "stack.h"
using namespace std;

int main()
{
    Stack<char> s1;
    Stack<char> s2;

    string str = "stressed";

    for (char ch : str)
    {
        s1.push(str);
    }

    // true is always true, so we will loop infinitely unless we
    // trigger the break statement below.

    while (true)
    {
        s2.push(s1.pop());

        // A break statement causes us to break out of whatever
        // loop it resides within. When this is executed, we jump
        // to the line immediately after the loop and continue
        // execution from there.
        if (s2.peek() == 'r')
        {
            break;
        }
    }

    // This is the line we jump to when we execute the break statement.

    cout << s1 << endl;
    cout << s2 << endl;
   
   return 0;
}