//
//  main.cpp
//  pdshow
//
//  Created by 张倬豪 on 2016/12/9.
//  Copyright © 2016年 Icarus. All rights reserved.
//

#include "diary.h"

int main(int argc,char *argv[])
{
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
    
    cout << "Please write the date of diary you want to read (In YYYY-MM-DD):" << endl;
    
    getline(cin, date);
    
    if (myDiary.find(date) == myDiary.end())
        cout<<"There is not such a diary which date is "<<date<<"."<<endl;
    else
    {
        vector<string>::size_type j;
        for (j = 0; j < myDiary[date].getSize(); j++) cout << myDiary[date].getText(j) << endl;
        cout << "." << endl;
    }
    //If the date matches, print the text
    
    return 0;
}
