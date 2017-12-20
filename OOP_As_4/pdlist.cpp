//
//  main.cpp
//  pdlist
//
//  Created by 张倬豪 on 2016/12/9.
//  Copyright © 2016年 Icarus. All rights reserved.
//

#include "diary.h"
#include <stdlib.h>

int main(int argc,char *argv[])
{
    map<string, Diary> myDiary;
    string oneLine;
    Diary diary;
    string date;
    ifstream input(data);
    
    while (!input.eof()) {
        getline(input, date);
        diary.setDate(date);
        diary.clearData();
        string oneline;
        getline(input, oneLine);
        while (oneLine != "" && oneLine != ".") {
            diary.add(oneLine);
            getline(input, oneLine);
        }
        myDiary[date] = diary;
    }
    input.close();
    if (argc == 3) {
        string begin = argv[1], end = argv[2];
        if (begin > end) {
            cout << "Error! Start date is bigger!" << endl;
            return 0;
        }
        map<string, Diary>::iterator i;
        for (i = myDiary.begin(); i != myDiary.end(); i++) {
            if (i ->second.getDate() >= begin && i ->second.getDate() <=end) {
                vector<string>::size_type j;
                cout << i ->second.getDate() << endl;
                for (j = 0; j < i ->second.getSize(); j++) cout << i ->second.getText(j) << endl;
                cout << "." << endl;
            }
        }
    }
    else {
        map<string, Diary>::iterator i;
        vector<string>::size_type j;
        for (i = myDiary.begin(); i != myDiary.end(); i++) {
            cout << i ->second.getDate() << endl;
            for (j = 0; j < i ->second.getSize(); j++) cout << i ->second.getText(j) << endl;
            cout << "." << endl;
        }
    }
    

    return 0;  
}