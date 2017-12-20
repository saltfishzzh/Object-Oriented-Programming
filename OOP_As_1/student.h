//
//  student.h
//  oop_1
//
//  Created by 张倬豪 on 2016/10/18.
//  Copyright © 2016年 Icarus. All rights reserved.
//

#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <string>
#include <iostream>

using namespace std;

class student {
public:
    void init();
    void print();
    
private:
    double student_ave(int num);
    double course_ave(int course_num);
    int find_max(int course_num);
    int find_min(int course_num);
    string name[10];
    double score1[10], score2[10], score3[10];
};

#endif /* _STUDENT_H_ */
