#include <iostream>
#include "console.h"
#include "SimpleTest.h"
#include "strlib.h"
using namespace std;

/*
1. #include "SimpleTest.h" in your code
2. Write your own tests using STUDENT_TEST("description of test") { ... }
3. Populate each SIMPLE_TEST with EXPECT_EQUAL( ... ) statements that verify the results of various operations.
4. Call runSimpleTests(ALL_TESTS) to cause the tests to be run.

Possible scenarios for testing extractAlpha():

1. What if all the characters are alphabetic?
2. What if there are non-alpha characters are at the end of the string?
3. What if there are non-alpha characters are at the beginning of the string?
4. What if there are non-alphabetic characters in the middle of the string?
5. What if there are alternating alphabetic and non-alphabetic characters?

6. What if we have only non-alphabetic characters, and no alphabetic ones?
7. What if our non-alphabetic characters are not digits, but other symbols ('$', '*', etc.)?
8. What if our string consists entirely of whitespace characters ('\n', spaces, and so on)?
9. What if we have an empty string (a string with zero characters)?

10. What if we have a string with exactly 1, 2, or 3 characters?
11. What if we have a very long string?
12. What if our string is even in length? What if the length is odd?
*/

string extractAlpha(string s)
{
   string result;

   for (int i = 0; i < s.length(); i++)
   {
      if (isalpha(s[i]))
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

STUDENT_TEST("various tests of extractAlpha() function")
{
    EXPECT_EQUAL(extractAlpha("sean"), "sean"); // case 1
    EXPECT_EQUAL(extractAlpha("sean11"), "sean"); // case 2
    EXPECT_EQUAL(extractAlpha("1sean"), "sean"); // case 3
    EXPECT_EQUAL(extractAlpha("s1ean"), "sean");
    EXPECT_EQUAL(extractAlpha("s1e1a1n"), "sean"); // case 5
    EXPECT_EQUAL(extractAlpha("s9e$a***&n"), "sean"); // case 4, 7
    EXPECT_EQUAL(extractAlpha(""), ""); // case 9
    EXPECT_EQUAL(extractAlpha("9$&"), ""); // case 6
}

int main()
{
    runSimpleTests(ALL_TESTS);

    string username = "Sean";
    string password = "s1e1a1n1'1s1p1a1s1s1w1o1r1d";

    if (isValidPassword(username, password))
    {
        cout << "Hooray!" << endl;
    }
    else
    {
        cout << "Oh no! Bad password." << endl;
    }

    return 0;
}