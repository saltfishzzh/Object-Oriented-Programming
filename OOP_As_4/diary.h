#ifndef _DIARY_H_
#define _DIARY_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
using namespace std;
#define data "diary.txt"

class Diary
{
public:
    void clearData();							//clear all the text of a diary
    void setDate(string d);						//set the date of a diary
    void add(string oneLine);					//add a single line to the text
    string getText(vector<string>::size_type i);//get the text of line i
    string getDate();							//get the date of a diary
    vector<string>::size_type getSize();		//get the size of the whole text
private:
    string date;
    vector<string> text;
};

#endif /* _DIARY_H_ */
