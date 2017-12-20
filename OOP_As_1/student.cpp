//
//  student.cpp
//  oop_1
//
//  Created by 张倬豪 on 2016/10/18.
//  Copyright © 2016年 Icarus. All rights reserved.
//

#include "student.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void student::init()
{
    int num;
    cin >> num;
    cin >> name[num - 1] >> score1[num - 1] >> score2[num - 1] >> score3[num - 1];
}

double student::student_ave(int num)
{
    if (num > 10) return -1;
    return (score1[num] + score2[num] +score3[num])/3.0;
}

double student::course_ave(int num)
{
    int i, sum = 0;
    switch (num) {
        case 1:
            for (i = 0; i < 10; i++) sum += score1[i];
            break;
            
        case 2:
            for (i = 0; i < 10; i++) sum += score2[i];
            break;
            
        case 3:
            for (i = 0; i < 10; i++) sum += score3[i];
            break;
            
        default:
            return -1;
            break;
    }
    return sum/10.0;
}

int student::find_max(int num)
{
    int i, max = 0;
    switch (num) {
        case 1:
            for (i = 0; i < 10; i++) if (score1[i] > max) max = score1[i];
            break;
            
        case 2:
            for (i = 0; i < 10; i++) if (score2[i] > max) max = score2[i];
            break;
            
        case 3:
            for (i = 0; i < 10; i++) if (score3[i] > max) max = score3[i];
            break;
            
        default:
            return -1;
            break;
    }
    return max;
    return 0;
}

int student::find_min(int num)
{
    int i, min = 6;
    switch (num) {
        case 1:
            for (i = 0; i < 10; i++) if (score1[i] < min) min = score1[i];
            break;
            
        case 2:
            for (i = 0; i < 10; i++) if (score2[i] < min) min = score2[i];
            break;
            
        case 3:
            for (i = 0; i < 10; i++) if (score3[i] < min) min = score3[i];
            break;
            
        default:
            return -1;
            break;
    }
    return min;
    return 0;
}

void student::print()
{
    int num;
    cout.setf(ios::left);
    cout <<"no      name    score1  score2  score3  average" << endl;
    for (num = 1; num <= 10; num++) cout << setw(8) << num << setw(8) << name[num - 1] << setw(8) << score1[num - 1] << setw(8) << score2[num - 1] << setw(8) << score3[num - 1] << setw(8) << student_ave(num) << endl;
    cout << setw(8) << " " << setw(8) << "average" << setw(8) << course_ave(1) << setw(8) << course_ave(2) << setw(8) << course_ave(3) << endl;
    cout << setw(8) << " " << setw(8) << "min" << setw(8) << find_min(1) << setw(8) << find_min(2) << setw(8) << find_min(3) << endl;
    cout << setw(8) << " " << setw(8) << "max" << setw(8) << find_max(1) << setw(8) << find_max(2) << setw(8) << find_max(3) << endl;
}







