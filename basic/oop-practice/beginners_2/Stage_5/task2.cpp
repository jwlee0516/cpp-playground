/*
  Note: The program demonstrates the implementation of a 'fraction' class 
  with various member functions to manipulate and compare fractions.
  It shows how overloaded operators can be used to perform arithmetic and 
  comparison operations on custom data types like fractions.
*/
#include <iostream>
using namespace std;

class fraction {
    private:
        static int fractionsCount;
        int numerator;
        int denominator;
    
    public:
        fraction(int n = 1, int d = 1);
        void setNum(int n);
        void setDen(int d);
        int getNum() const;
        int getDen() const;

        fraction operator+(const fraction& f) const;
        fraction operator*(const fraction& f) const;
        bool operator>(const fraction& f) const;

        bool isProper() const;
        static int getCount();
        void show() const;
}

int fraction::fractionsCount = 0;

fraction::fraction(int n, int d) {
    if (d == 0) d = 1;

    this->numerator = n;
    this->denominator = d;
    fractionsCount++;
}

void fraction::setNum(int n) {
    this->numerator = n;
}

void fraction::setDen(int d) {
    if (d != 0) {
        this->denominator = d;
    }
}

int fraction::getNum() const {
    return numerator;
}

int fraction::getDen() const {
    return denominator;
}

fraction fraction::operator+(const fraction& f) const {
    fraction result;
    result.numerator = (numerator * f.denominator) + (f.numerator * denominator);
    result.denominator = denominator * f.denominator;

    int div = 2;
    while (div <= result.numerator && div <= result.denominator) {
        if (result.numerator % div == 0 && result.denominator % div == 0) {
            result.numerator /= div;
            result.denominator /= div;
        } else {
            div++;
        }
    }
    return result;
}

fraction fraction::operator*(const fraction& f) const {
    fraction result;
    result.numerator = numerator * f.numerator;
    result.denominator = denominator * f.denominator;

    int div = 2;
    while (div <= result.numerator && div <= result.denominator) {
        if (result.numerator % div == 0 && result.denominator % div == 0) {
            result.numerator /= div;
            result.denominator /= div;
        } else {
            div++;
        }
    }
    return result;
}

bool fraction::operator>(const fraction& f) const {
    if (denominator == f.denominator) {
        return numerator > f.numerator;
    } else {
        return numerator * f.denominator > f.numerator * denominator;
    }
}

bool fraction::isProper() const {
    return numerator > denominator;
}

int fraction::getCount() {
    return fractionsCount;
}

