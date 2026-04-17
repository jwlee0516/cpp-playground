#include <iostream>
#include "console.h"
#include "strlib.h"
using namespace std;

int main()
{
    string s = "Sean";
    string p = "s1e1a1n1'1s1p1a1s1s1w1o1r1d";
    string p0;

    for (int i = 0; i < p.length(); i++)
    {
        if(isalpha(p[i]))
        {
            p0 += p[i];
        }
    }

    // How can we determine whether the given username (s) appears in the password (p)?
    if(stringContains(toLowerCase(p), toLowerCase(s)))
    {
        cout << "Uh oh! Bad password." << endl;
    }
    else 
    {
        cout << "Hooray!" << endl;
    }

    return 0;
}