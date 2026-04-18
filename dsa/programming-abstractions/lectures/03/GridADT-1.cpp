/*

Grid Overview -> Matrix

A rectangular array. A vector of vectors. Grids can be used to represent all kinds of things, including:

    1. spreadsheets (where element in a grid corresponds to a cell in a spreadsheet)
    2. game boards (e.g., an 8x8 grid of characters indicating locations of pieces on a chess board)
    3. images (a grid of color codes, one for each pixel in an image)

Like a vector, the elements in a grid are ordered and indexed. 
A grid has some number of rows (horizontal) and columns (vertical).

** Think of it as a matrix (rows, columns) 2 x 3, 2 x 2....

*/

#include <iostream>
#include "console.h"
#include "grid.h"
using namespace std;

int main() 
{
    Grid<int> g(3, 4);

    // Values in an integer grid are zeroed out by default. At this point, we have:
    //     +----+----+----+----+
    //  0  | 0  | 0  | 0  | 0  |
    //     +----+----+----+----+
    //  1  | 0  | 0  | 0  | 0  |
    //     +----+----+----+----+
    //  2  | 0  | 0  | 0  | 0  |
    //     +----+----+----+----+
    //       0    1    2    3

    // We can update the value at row 2, column 3, like so (see corresponding
    // cell highlighted in the diagram below):

    g[2][3] = 18;

    // We now have:
    //    +----+----+----+----+
    //  0 | 0  | 0  | 0  | 0  |
    //    +----+----+----+----+
    //  1 | 0  | 0  | 0  | 0  |
    //    +----+----+----+----+
    //  2 | 0  | 0  | 0  | 18 |
    //    +----+----+----+----+
    //      0    1    2    3

    // Print an entire grid. For each row, print the values in each column.
    for (int i = 0; i < g.numRows(); i++)
    {
        for (int j = 0; j < g.numCols(); j++)
        {
            cout << g[i][j];

            // If not the last element in this row, print a comma and a space.
            if(j != g.numCols() - 1)
            {
                cout << ", ";
            }
        }
        cout << endl;
    }

    return 0;
}