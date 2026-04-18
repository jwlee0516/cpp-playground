/*

Four Ways to Print Grid Contents

    1. Use a for-each loop (i.e., "enhanced for-loop" or "range-based loop") to loop through and 
    display the contents of a grid. These are processed in a row-major fashion. Note that this approach 
    does not give us access to the row and column of the element being processed within the loop.

    2. We can use nested for loops to display the contents of a grid in the same order as above.

    3. We can loop through all the valid coordinates in a grid as GridLocation objects
       and those can be used to access specific grid elements.

    4. We can send a grid directly to cout and get a nicely formatted string that conveys 
       the grid contents. This approach prints contents in a row-major fashion, as well.
*/

#include <iostream>
#include "console.h"
#include "grid.h"
using namespace std;

int main()
{
    Grid<int> g(2, 3);

    // Just random values. :)
    g[0][0] = 41;
    g[0][1] = 53;
    g[0][2] = 98;
    g[1][0] = 18;
    g[1][1] = 21;
    g[1][2] = 16;

    // Option #1: For-Each Loop
    cout << "Grid for-each loop:" << endl;
    for (int i : g)
    {
        cout << i << endl;
    }
    cout << endl;

    // Option #2: Nested for loops.
    cout << "Grid nested loops:" << endl;
    for (int row = 0; row < g.numRows(); row++)
    {
        for (int col = 0; col < g.numCols(); col++)
        {
            cout << g[row][col] << endl;
        }
    }
    cout << endl;

    // Option #3: Iterate over grid locations.
    cout << "Grid locations:" << endl;
    for (GridLocation loc : g.locations())
    {
        cout << loc << " -> " << g[loc] << endl;
    } 
    cout << endl;

    // Option #4: Just dump directly to cout.
    cout << "Grid contents:" << endl;
    cout << g << endl << endl;

    // Example of manual specification of GridLocation.
    GridLocation myLoc(0, 1);
    cout << g[myLoc] << endl;

    return 0;
}

/*

Q: why would we pass the vector by reference if we have no intention of modifying it in the printVector() function? 

A: We often pass containers to functions by reference simply to save time and space (i.e., memory). 
If we pass a HUGE vector to a function by value, our function has to create a whole separate copy of that 
vector's contents, which takes time in addition to using up extra memory (since we'll have a second copy of 
the vector hanging around in memory). Passing by reference is a smaller, faster transaction 
and is sometimes done simply for the sake of efficiency.

*/