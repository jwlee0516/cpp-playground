/*
Set Applications: Removing Duplicates

We can use a set to very easily solve the problem from above of printing all the unique elements 
in some vector (with no duplicates). We we can just toss them into a set and print the set, 
letting our ADT do all the heavy lifting for us!
*/

#include <iostream>
#include "console.h"
#include "set.h"
#include "vector.h"
using namespace std;

void removeDuplicates1()
{
    Vector<string> creatures = {"unicorn", "starfish", "hummingbird", "starfish", "unicorn", "unicorn"};
    Set<string> seen;

    for (string s : creatures)
    {
        seen.add(s);
    }

    cout << seen << endl;
    return 0; 

}

// Instead of printing the unique elements in a vector, we could print all the duplicate elements like so:
void printDuplicates()
{
    Vector<string> creatures = {"unicorn", "starfish", "hummingbird", "starfish", "unicorn", "unicorn"};
    Set<string> seen;

    for (string s : creatures)
    {
        if (seen.contains())
        {
            cout << "OoOOOh! Dupe! " << s << endl;
        }

        // Note that if we see a duplicate in our vector, the following line doesn't
        // add a second copy to the set since sets don't allow duplicates.
        seen.add(s);
    }

    return 0;
}

