//
//  fraction.hpp
//  oop_5
//
//  Created by 张倬豪 on 2016/12/13.
//  Copyright © 2016年 Icarus. All rights reserved.
//

#ifndef fraction_h
#define fraction_h

#include <iostream>
#include <string>

using namespace std;

class fraction {
public:
    fraction();
    fraction(const fraction& f);
    fraction(const int numerator, const int denominator):
        nume(numerator), deno(denominator) {reduction();}
    const int getNume();
    const int getDeno();
    void reduction();
    fraction operator+(const fraction& fra);
    fraction operator-(const fraction& fra);
    fraction operator*(const fraction& fra);
    fraction operator/(const fraction& fra);
    bool operator<(const fraction& fra);
    bool operator<=(const fraction& fra);
    bool operator==(const fraction& fra);
    bool operator!=(const fraction& fra);
    bool operator>=(const fraction& fra);
    bool operator>(const fraction& fra);
    double toDouble();
    string toString();
    friend istream& operator>>(istream& in, fraction& fra);
    friend ostream& operator<<(ostream& os, const fraction& fra);
    virtual ~fraction(){}
private:
    int nume;
    int deno;
};

istream& operator>>(istream& in, fraction& fra);
ostream& operator<<(ostream& os, fraction& fra);

#endif /* fraction_hpp */
