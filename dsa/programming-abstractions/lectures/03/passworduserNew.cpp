#include <iostream>
#include "console.h"
#include "strlib.h"
using namespace std;
/*
several flaws that make it difficult to read and, 
therefore, difficult to debug, augment, and maintain.

1. not using meaningful variable names.

2. Everything is dumped into main(), leading to code that is difficult 
for someone who's not familiar with the code to parse through and debug. 
As written, if our program isn't working correctly, it can be hard to 
determine where things are going wrong, because there's so much happening 
all in one place. 
It's also hard to subject individual components of the code to robust testing 
when they're all slopped into main() like this.

3. There are no comments to assist the reader in figuring out what's going on. 
However, the ideal scenario would be to rewrite the code in a way that makes comments somewhat unnecessary.

Solution: solve the broader structural issues by moving chunks of code 
into functions that serve a single purpose and naming those functions 
with verb phrases that conveyed what they do

FUNCTIONAL DECOMPOSITION: Breaking up a task into constituent functions that each fulfill a single purpose
    ㄴ> improves the readability and maintainability of our code

*/

string extractAlpha(string s)
{
    string result;
    for (int i = 0; i < s.length(); i++)
    {
        if(isalpha(s[i]))
        {
            result += s[i];
        }
    }
    return result;
}

bool isValidPassword(string username, string password)
{
    string alphaPortion = extractAlpha(password);
    return !stringContains(toLowerCase(alphaPortion), toLowerCase(username));
}

int main()
{
    string username = "Sean";
    string password = "s1e1a1n1'1s1p1a1s1s1w1o1r1d";

    if(isValidPassword(username, password))
    {
        cout << "Hooray!" << endl;
    }
    else
    {
      cout << "Oh no! Bad password." << endl;
    }
   return 0;
}