//
//  student.h
//  oop_2
//
//  Created by 张倬豪 on 2016/11/8.
//  Copyright © 2016年 Icarus. All rights reserved.
//

#ifndef student_h
#define student_h
#include <vector>
#include <map>
#include <string>

using namespace std;

typedef struct point stu;
struct point {
    string name;
    map<string, double> course;     //store one student's grades
};

/*student_table -- simple input, save, process and print students' grades*/
class student_table {
public:
    void init();    //input students' data
    void print();   //print students' data in a summary sheet
private:
    vector<stu> student;                    //a vector container that stores students' data
    map<string, int> courses;               //a map container that stores all the courses
    double max(string course);         //find the maximum of a course
    double min(string course);         //find the minimum of a course
    double courseave(string course);  //calculate the course average
    double studentave(stu stud);      //calculate the students' average
};


#endif /* student_h */
