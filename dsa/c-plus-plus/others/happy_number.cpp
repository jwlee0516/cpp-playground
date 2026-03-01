/**
 * @file
 * @brief A happy number is a number whose sum of digits is calculated until the
 * sum is a single digit, and this sum turns out to be 1
 */

#include <iostream>

/**
 * Checks if a decimal number is a happy number
 * \returns true if happy else false
 */

 template <typename T>
 bool is_Happy (T n){
    T s = 0;
    while (n > 9){
        while (n != 0){
            T d = n % 10;
            s += d;
            n /= 10;
        }
        n = s
        s = 0;
    }
    return (n == 1) ? true : false; // true if k == 1
 }

 int main(){
    int n;
    std::cout << "Enter a number:";
    std::cin >> n;

    if (is_Happy(n))
        std::cout << n << " is a happy number" << std::endl;
    else
        std::cout << n << " is not a happy number" << std::endl;
    return 0;

 }