//
//  fraction.cpp
//  oop_5
//
//  Created by 张倬豪 on 2016/12/13.
//  Copyright © 2016年 Icarus. All rights reserved.
//

#include "fraction.h"

fraction::fraction(const fraction& f):nume(f.nume), deno(f.deno) {}

const int fraction::getNume() {
    return nume;
}

const int fraction::getDeno() {
    return deno;
}

void fraction::reduction() {
    int n = this->getNume();
    int d = this->getDeno();
    int temp = 2;
    while (d != 1 && temp <= d) {
        if (n % temp == 0 && d % temp == 0) {
            n = n / temp;
            d = d / temp;
        }
        temp++;
    }
    this->nume = n;
    this->deno = d;
}

fraction fraction::operator+(const fraction &fra) {
    fraction temp = *this;
    temp.nume = temp.nume * fra.deno + temp.deno * fra.nume;
    temp.deno = temp.deno * fra.deno;
    temp.reduction();
    return temp;
}

fraction fraction::operator-(const fraction &fra) {
    fraction temp = *this;
    temp.nume = temp.nume * fra.deno - temp.deno * fra.nume;
    temp.deno = temp.deno * fra.deno;
    temp.reduction();
    return temp;
}

fraction fraction::operator*(const fraction &fra) {
    fraction temp = *this;
    temp.nume = temp.nume * fra.nume;
    temp.deno = temp.deno * fra.deno;
    temp.reduction();
    return temp;
}

fraction fraction::operator/(const fraction &fra) {
    fraction temp = *this;
    temp.nume = temp.nume * fra.deno;
    temp.deno = temp.deno * fra.nume;
    temp.reduction();
    return temp;
}

bool fraction::operator<(const fraction &fra ) {
    if (fra.nume * this->deno - fra.deno * this->nume > 0) return 1;
    return 0;
}

bool fraction::operator<=(const fraction &fra ) {
    if (fra.nume * this->deno - fra.deno * this->nume >= 0) return 1;
    return 0;
}

bool fraction::operator==(const fraction &fra ) {
    return fra.nume * this->deno == fra.deno * this->nume;
}

bool fraction::operator!=(const fraction &fra ) {
    return fra.nume * this->deno != fra.deno * this->nume;
}

bool fraction::operator>=(const fraction &fra ) {
    if (fra.nume * this->deno - fra.deno * this->nume <= 0) return 1;
    return 0;
}

bool fraction::operator>(const fraction &fra ) {
    if (fra.deno * this->nume - fra.nume * this->deno > 0) return 1;
    return 0;
}

double fraction::toDouble() {
    double n = nume;
    double d = deno;
    return n / d;
}

string fraction::toString() {
    this->reduction();
    return to_string(nume) + '/' + to_string(deno);
}

istream& operator>>(istream &in, fraction& fra) {
    char ch;
    int n, d;
    in >> n >> ch >> d;
    fra.nume = n;
    fra.deno = d;
    fra.reduction();
    return in;
}

ostream& operator<<(ostream &os, fraction& fra) {
    os <<  fra.getNume() << '/' << fra.getDeno();
    return os;
}
