//
//  main.cpp
//  pdadd
//
//  Created by 张倬豪 on 2016/12/8.
//  Copyright © 2016年 Icarus. All rights reserved.
//

#include "diary.h"

int main(int argc,char *argv[])  {
    map<string, Diary> myDiary;//Use map STL to store a diary(<first, second> == <date, diary>)
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
    //Read file. The same for every sub-program
    
    cout << "Please write your diary (In YYYY-MM-DD):" << endl;
    
    getline(cin, date);
    diary.clearData();
    diary.setDate(date);
    getline(cin, oneLine);
    while (oneLine != ".") {
        diary.add(oneLine);
        getline(cin, oneLine);
    }
    
    myDiary[date] = diary;
    //Add the new diary

    ofstream output(data);
    map<string, Diary>::iterator i;
    vector<string>::size_type j;
    map<string, Diary>::size_type k = 0;
    for (i = myDiary.begin(); i != myDiary.end(); i++) {
        output << i ->second.getDate() << endl;
        for (j = 0; j < i ->second.getSize(); j++) output << i ->second.getText(j) << endl;
        output << ".";
        if (k != myDiary.size() - 1) output << endl;
        k++;
    }
    //Rewrite all the diaries
    output.close();

    return 0;
}
