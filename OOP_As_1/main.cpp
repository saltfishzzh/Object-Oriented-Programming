//
//  main.cpp
//  oop_1
//
//  Created by 张倬豪 on 2016/10/8.
//  Copyright © 2016年 Icarus. All rights reserved.
//

#include <iostream>
#include "student.h"

using namespace std;

int main(int argc, const char * argv[]) {
    int i;
    student student_table;
    for (i = 0; i < 10; i++) student_table.init();
    student_table.print();
    return 0;
}
