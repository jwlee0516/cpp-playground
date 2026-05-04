/*

Sortedness of Set Elements

Sets always appeared in alphabetical order when we printed them out. Behind the scenes, 
the Stanford set is using a data structure that keeps the elements in some kind of 
sorted order so that we can have really fast insertion and look-up operations.

*/

#include <iostream>
#include "console.h"
#include "set.h"
using namespace std;

int main()
{
    Set<string> set = {"unicorn", "starfish", "hummingbird", "starfish", "unicorn", "unicorn"};

    set.add("Phoenix");
    set.remove("hummingbird");
    set.add("dragon");

    cout << set << endl;
    cout << "Set size: " << set.size() << endl;

    /*
        we can use a for-each loop to run through the elements of a set, and the elements are processed 
        in the same order in which they appear when printing the set using cout << set:

        ** we can't use a traditional for-loop with an index i to loop through the set, though, 
           since there is no index associated with each element.
    */
    for (string s : set)
    {
        cout << "-> " << s << endl;   
    }

    return 0;
}

/*

Our output is no longer in alphabetic order. It is, however, sorted using what some people call ASCIIbetical order.
    
  WHY? Characters in C++ are represented using ASCII values. The ASCII values for uppercase letters come before 
       the ASCII values for lowercase letters. (For example: 'A' = 65, 'Z' = 90, 'a' = 97, and 'z' = 122.) 
       The set uses those ASCII values to sort the strings, and so strings that start with uppercase letters 
       end up coming before those that start with lowercase letters.
*/