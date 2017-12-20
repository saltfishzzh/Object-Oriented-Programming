//
//  student.cpp
//  oop_2
//
//  Created by 张倬豪 on 2016/11/8.
//  Copyright © 2016年 Icarus. All rights reserved.
//

#include <iostream>
#include "student.h"

/*************************************************
 Function:      //input students' data
 Description:   //while the input is not EOF, keep
                  reading. if the student's ID is
                  already been read, read the scores.
                  Or push back a new vector.
 Calls:         //None
 Input:         //None
 Output:        //None
 Return:        //None
 Others:        //None
 *************************************************/
void student_table::init() {
    string name;
    string course;
    double score;
    int flag;
    cout << "Please Input a line like this: stuID course score" << endl;
    while (cin >> name) {
        flag = 1;
        cin >> course >> score;
        vector<stu>::iterator i;
        for (i = student.begin(); i < student.end(); i++) if (name == i ->name) {
            i ->course.insert(pair<string,double>(course, score));
            courses[course]++;
            flag = 0;
        }
        if (flag) {
            stu *temp = new stu;
            temp ->name = name;
            temp ->course.insert(pair<string, double>(course, score));
            student.push_back(*temp);
            delete temp;
            courses[course]++;
        }
    }
}

/*************************************************
 Function:      //find the maximum of a course
 Description:   //iterate the student vector and 
                  find the max
 Calls:         //None
 Input:         //string course
 Output:        //None
 Return:        //max
 Others:        //None
 *************************************************/
double student_table::max(string course) {
    double max = 0;
    vector<stu>::iterator i;
    for (i = student.begin(); i < student.end(); i++) {
        if (i ->course[course] > max) max = i ->course[course];
    }
    return max;
}

/*************************************************
 Function:      //find the minimum of a course
 Description:   //iterate the student vector and
                  find the min
 Calls:         //None
 Input:         //string course
 Output:        //None
 Return:        //min
 Others:        //None
 *************************************************/
double student_table::min(string course) {
    double min = 1 << 10;
    vector<stu>::iterator i;
    for (i = student.begin(); i < student.end(); i++) {
        if (i ->course[course] < min &&  i ->course[course] > 0) min = i ->course[course];
    }
    return min;
}

/*************************************************
 Function:      //calculate the course average
 Description:   //iterate the student vector if the
                  course exists, add it to the sum
 Calls:         //None
 Input:         //string course
 Output:        //None
 Return:        //the average of course
 Others:        //None
 *************************************************/
double student_table::courseave(string course) {
    double score = 0;
    int num = 0;
    vector<stu>::iterator i;
    for (i = student.begin(); i < student.end(); i++) if (i ->course[course] > 0) {
        score += i ->course[course];
        num++;
    }
    return score / num;
}

/*************************************************
 Function:      //calculate the student's average
 Description:   //iterate the student vector
 Calls:         //None
 Input:         //stu student (it is a struct)
 Output:        //None
 Return:        //the average of student's grades
 Others:        //None
 *************************************************/
double student_table::studentave(stu stud) {
    double score = 0;
    int num = 0;
    map<string, double> temp = stud.course;
    map<string, double>::iterator i;
    for (i = temp.begin(); i != temp.end(); i++) {
        if (i ->second > 0) {
            score += i ->second;
            num++;
        }
    }
    return score / num;
}

/*************************************************
 Function:      //print the summary sheet
 Description:   //print each student's grades and
                  each course's data
 Calls:         //None
 Input:         //None
 Output:        //None
 Return:        //None
 Others:        //None
 *************************************************/
void student_table::print() {
    cout << "Students: " << endl;
    vector<stu>::iterator i;
    for (i = student.begin(); i < student.end(); i++) {
        cout << "ID: " << i ->name << endl << "Scores: ";
        map<string, double>::iterator j;
        for (j = i ->course.begin(); j != i ->course.end(); j++) {
            cout << j ->first << " " << j ->second << " ";
        }
        cout << studentave(*i) << endl;
    }
    cout <<endl << "Courses: " << endl;
    map<string, int>::iterator k;
    for (k = courses.begin(); k != courses.end(); k++) {
        cout <<"Name: " << k ->first;
        cout <<" Average: " << courseave(k ->first) << " ";
        cout << "Max: " << max(k ->first) << " ";
        cout << "Min: " << min(k ->first) << endl;
    }
}
