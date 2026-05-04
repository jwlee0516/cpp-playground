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

}

// when it prints all the duplicate elements in some vector, it only prints each 
// duplicate once, no matter how many times it's duplicated in the array
void printDuplicates2()
{
    Vector<string> creatures = {"unicorn", "starfish", "hummingbird", "starfish", "unicorn", "unicorn"};
    Set<string> seen;
    Set<string> alreadyPrinted;

    for (string s : creatures)
    {
        if (seen.contains(s))
        {
            // If we haven't printed this one yet, go ahead and print. Then add
            // to our alreadyPrinted set so it won't get printed again.
            if(!alreadyPrinted.contains(s))
            {
                cout << s << endl;
                alreadyPrinted.add(s);
            }
        }

        // Keep track of all the elements we have seen.
        seen.add(s);
    }
}

void printDuplicates3()
{
    Vector<string> creatures = {"unicorn", "starfish", "hummingbird", "starfish", "unicorn", "unicorn"};
    Set<string> seen;
    Set<string> dupes;

    for (string s : creatures)
    {
        if (seen.contains(s))
        {
            // Keep track of each element that we have seen more than once.
            dupes.add(s);
        }

        // Keep track of all the elements we have seen.
        seen.add(s);
    }

    cout << dupes << endl;

}

void vectorTOSet()
{
    Vector<string> creatures = {"unicorn", "starfish", "hummingbird", "starfish", "unicorn", "unicorn"};
    Set<string> seen;

    for (string s : creatures)
    {
        seen.add(s);
    }

    creatures.clear();

    for (string s : seen)
    {
        creatures.add(s);
    }

    cout << creatures << endl;

}