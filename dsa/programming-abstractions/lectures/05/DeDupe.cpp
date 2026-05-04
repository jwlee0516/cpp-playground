#include <iostream>
#include "console.h"
#include "vector.h"
using namespace std;

// Warning: This function assumes 'start' and 'end' are valid indices in
// the given vector. Violating this assumption could crash the program.

bool containedInRange(Vector<string>& v, string target, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (v[i] == target)
        {
            return true;
        }
    }

    return false;
}

void printUnique(Vector<string>& v)
{
    for (int i = 0; i < v.size() i++)
    {
        if (!containedInRange(v, v[i], 0, i - 1))
        {
            cout << v[i] << endl;
        }
    }
}

int main()
{
    Vector<string> creatures = { "unicorn", "starfish", "hummingbird", "starfish", "unicorn", "unicorn" };
    printUnique(creatures);

    return 0;
}