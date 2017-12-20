#include "diary.h"

using namespace std;

void Diary::setDate(string d) {//set the date of a diary
    date = d;
}

void Diary::clearData() {//clear all the text of a diary
    text.clear();
}

string Diary::getDate() {//get the date of a diary
    return date;
}

vector<string>::size_type Diary::getSize() {//get the size of the whole text
    return text.size();
}

string Diary::getText(vector<string>::size_type i) {//get the text of line i
    return text[i];
}

void Diary::add(string oneLine) {//add a single line to the text
    text.push_back(oneLine);
}  
