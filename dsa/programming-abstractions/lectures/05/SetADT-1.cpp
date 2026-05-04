/*
Set Overview
A set is a collection that does not allow duplicates or preserve the order in which elements are inserted. 

    1. Just like the sets we're familiar with from math classes, a set data structure does not 
       allow duplicate elements. If we insert the same element into some set multiple times, 
       the set still only contains one copy of that element. Thus, a set only ever contains either 
       zero copies or one copy of some element.

    2. A set does not maintain the order in which elements are inserted; if we iterate over all the 
       elements in a set, they are not guaranteed to be in the same order in which they were insert. 
       There is no notion of each element having an index (as with vectors) and there is  not necessarily 
       a notion of an element's relative positioning within a set.

    Think of sets primarily as binary membership devices: an element is either a member of a set, or it isn't.

    Keyword: type-parameter / template parameter 
        Set< DATA_TYPE >  VARIABLE_NAME ; - specify the element type for that set as a type parameter:
*/

#include <iostream>
#include "console.h"
#include "set.h"
using namespace std;

int main()
{
    Set<string> set = { "unicorn", "starfish", "hummingbird", "starfish", "unicorn", "unicorn" };

    cout << set << endl;
    cout << "Set size: " << set.size() << endl;

    set.add("dragon");
    set.remove("hummingbird");

    return 0;
}