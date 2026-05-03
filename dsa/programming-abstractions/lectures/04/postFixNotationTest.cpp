#include <iostream>
#include "console.h"
#include "SimpleTest.h"
#include "stack.h"
#include "strlib.h"
using namespace std;

PROVIDED_TEST("valid postfix expressions")
{
    int result = 0;
    EXPECT_EQUAL(processPostfix("5 10 + ", result), true);
    EXPECT_EQUAL(result, 15);

    EXPECT_EQUAL(processPostfix("3 8 *", result), true);
    EXPECT_EQUAL(result, 24);

    EXPECT_EQUAL(processPostfix("5 10 12 + -", result), true);
    EXPECT_EQUAL(result, -17);

    EXPECT_EQUAL(processPostfix("10 12 + 5 -", result), true);
    EXPECT_EQUAL(result, 17);

    EXPECT_EQUAL(processPostfix("2 3 + 4 5 + *", result), true);
    EXPECT_EQUAL(result, 45);

    EXPECT_EQUAL(processPostfix("2 3 1 * + 9 -", result), true);
    EXPECT_EQUAL(result, -4);

    EXPECT_EQUAL(processPostfix("10", result), true);
    EXPECT_EQUAL(result, 10);

}

PROVIDED_TEST("invalid postfix expressions")
{
    int result = 0;

    EXPECT_EQUAL(processPostfix("5 10 + +", --result), false);
    EXPECT_EQUAL(result, -1);

    EXPECT_EQUAL(processPostfix("3 8 * 0 / 5 +", --result), false);
    EXPECT_EQUAL(result, -2);

    EXPECT_EQUAL(processPostfix("", --result), false);
    EXPECT_EQUAL(result, -3);

    EXPECT_EQUAL(processPostfix("10 12 + 13", --result), false);
    EXPECT_EQUAL(result, -4);

    EXPECT_EQUAL(processPostfix("10 12 13 +", --result), false);
    EXPECT_EQUAL(result, -5);

    EXPECT_EQUAL(processPostfix("10 + 20", --result), false);
    EXPECT_EQUAL(result, -6);

    EXPECT_EQUAL(processPostfix("- 10 8", --result), false);
    EXPECT_EQUAL(result, -7);

    EXPECT_EQUAL(processPostfix("- 10", --result), false);
    EXPECT_EQUAL(result, -8);

    EXPECT_EQUAL(processPostfix("-", --result), false);
    EXPECT_EQUAL(result, -9);

    EXPECT_EQUAL(processPostfix("10 15 + sandwhich", --result), false);
    EXPECT_EQUAL(result, -10);
}

int main()
{
    runSimpleTests(ALL_TESTS);
    return 0;
}

/*

Q1. What errors might we encounter while processing a postfix expression that would indicate that the 
expression was invalid or malformed? Account for each of these scenarios.

    1. Encountering a token in our input string that is neither an integer nor a valid operator.

    2. Encountering an operator in our expression when stack.size() < 2. In this case, we don't 
       have enough operands to perform the desired operation.

    3. Encountering division by zero.

    4. Encountering a final stack with stack.size() != 1. If there is nothing in the stack when 
       we finish processing our expression, or if the final stack contains multiple values, 
       the original expression must have been malformed.


Q2. In the test cases for invalid postfix expressions given above, result is being decremented with 
each new test case. What benefit does this have compared to simply setting result = -1 and always 
checking that result is still -1 when returning from each of those individual test cases?

    If we always check that result is -1 in those test cases, someone might think the goal of processPostfix() is 
    to set result equal to -1 in the event that a postfix expression is malformed, and if they did so, they would 
    get a false sense of security from passing all those test cases. In actuality, the function is supposed to 
    leave that parameter completely unchanged when it encounters a malformed postfix expression. Changing result 
    before we make a new call to processPostfix() with a malformed expression -- and checking that its value is 
    unchanged when we return from that function -- more clearly conveys (and tests!) that desired behavior.
*/