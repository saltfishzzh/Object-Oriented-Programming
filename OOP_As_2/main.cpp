//
//  main.cpp
//  oop_2
//
//  Created by 张倬豪 on 2016/11/8.
//  Copyright © 2016年 Icarus. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "student.h"

using namespace std;

int main(int argc, const char * argv[]) {
    student_table stud;
    stud.init();
    stud.print();
    return 0;
}
