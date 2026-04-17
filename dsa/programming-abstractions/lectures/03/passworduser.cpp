#include <iostream>
#include "console.h"
#include "strlib.h"
using namespace std;

int main()
{
    string s = "Sean";
    string p = "sean'spassword";

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