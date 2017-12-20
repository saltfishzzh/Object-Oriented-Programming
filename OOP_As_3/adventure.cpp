//
//  adventure.cpp
//  oop3
//
//  Created by 张倬豪 on 2016/11/29.
//  Copyright © 2016年 Icarus. All rights reserved.
//

#include "adventure.h"
#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

extern bool getP;
extern lobby lob;
extern basicRoom room1;
extern basicRoom room2;
extern basicRoom room3;
extern basicRoom room4;
extern basicRoom room5;
extern basicRoom room6;
extern portal por;

void buildCastle() {
    lob.exits.insert(pair<string, basicRoom*>("east",&room1));
    lob.exits.insert(pair<string, basicRoom*>("north",&room2));
    room1.exits.insert(pair<string, basicRoom*>("west",&lob));
    room1.exits.insert(pair<string, basicRoom*>("south",&room3));
    room2.exits.insert(pair<string, basicRoom*>("south",&lob));
    room2.exits.insert(pair<string, basicRoom*>("up",&room4));
    room3.exits.insert(pair<string, basicRoom*>("north",&room1));
    room3.exits.insert(pair<string, basicRoom*>("east",&room6));
    room3.exits.insert(pair<string, basicRoom*>("down",&room5));
    room4.exits.insert(pair<string, basicRoom*>("down",&room2));
    room5.exits.insert(pair<string, basicRoom*>("up",&room3));
    room5.exits.insert(pair<string, basicRoom*>("mysteryExit",&por));
    room6.exits.insert(pair<string, basicRoom*>("west",&room3));
    por.exits.insert(pair<string, basicRoom*>("back",&room5));
}

void setPM(int princessRoomNum, int monsterRoomNum) {
    switch (princessRoomNum) {
        case 1:
            room1.setPrincess();
            por.exits.insert(pair<string, basicRoom*>("left",&room1));
            break;
        case 2:
            room2.setPrincess();
            por.exits.insert(pair<string, basicRoom*>("left",&room2));
            break;
        case 3:
            room3.setPrincess();
            por.exits.insert(pair<string, basicRoom*>("left",&room3));
            break;
        case 4:
            room4.setPrincess();
            por.exits.insert(pair<string, basicRoom*>("left",&room4));
            break;
        case 5:
            room5.setPrincess();
            por.exits.insert(pair<string, basicRoom*>("left",&room5));
            break;
        case 6:
            room6.setPrincess();
            por.exits.insert(pair<string, basicRoom*>("left",&room6));
            break;
        default: break;
    }
    switch (monsterRoomNum) {
        case 1:
            room1.setMonster();
            por.exits.insert(pair<string, basicRoom*>("right",&room1));
            break;
        case 2:
            room2.setMonster();
            por.exits.insert(pair<string, basicRoom*>("right",&room2));
            break;
        case 3:
            room3.setMonster();
            por.exits.insert(pair<string, basicRoom*>("right",&room3));
            break;
        case 4:
            room4.setMonster();
            por.exits.insert(pair<string, basicRoom*>("right",&room4));
            break;
        case 5:
            room5.setMonster();
            por.exits.insert(pair<string, basicRoom*>("right",&room5));
            break;
        case 6:
            room6.setMonster();
            por.exits.insert(pair<string, basicRoom*>("right",&room6));
            break;
        default: break;
    }
}

basicRoom::basicRoom(const basicRoom& br):
    exits(br.exits),
    name(br.name),
    princess(br.princess),
    monster(br.monster)
{   }

lobby::lobby(): basicRoom("lobby") {}

portal::portal(): basicRoom("portal") {}

void basicRoom::showInfo() {
    if (!monster) {
        if (!princess) {
            cout << "Welcome to the " << name << ". There are " << (int) exits.size() << " exits as: ";
        }
        // If the user doesn't meet the princess
        else {
            cout << "Congratulations! You found the princess! Now you need to get out. There are " << (int) exits.size() << " exits as: ";
            getP = true;
        }
        // If the user meet the princess
        map<string, basicRoom*>::iterator i;
        for (i = exits.begin(); i != exits.end(); i++) cout << i ->first << " ";
        cout << endl << "Enter your command:Go " ;
    }
    // If the user doesn't meet the monster
    else {
        cout << "You had encountered the monster! Game Over!" << endl;
    }
}

basicRoom* basicRoom::goNext(const string& direction) {
    if (exits.find(direction) == exits.end()) {
        cout << "No such direction, please enter again!" << endl;
        return this;
    }
    // If the direction user inputed does not exists
    return exits.find(direction) ->second;
    // Return the next room the user got in
}

void lobby::showInfo() {
    if (getP) {
        cout << "You won the game!" << endl;
        return;
    }
    // If the user got the princess and gets out
    if (!lobbyAgain) {
        cout << "This is a castle, you need to find the princess and be careful not to encounter the monster. Good Luck! Please press any key" << endl;
        getchar();
    }
    cout << "Welcome to the lobby. There are " << (int) exits.size() << " exits as: ";
    map<string, basicRoom*>::iterator i;
    for (i = exits.begin(); i != exits.end(); i++) cout << i ->first << " ";
    cout << endl << "Enter your command:Go " ;
    lobbyAgain = true;
}

void portal::showInfo() {
    if (getP) {
        cout << "You have already got the princess, you should go back!" << endl;
        return;
    }
    // If the user had already got the princess
    cout << "Welcome to the portal, you have three ways, go back, go left or go right. If you are brave, you should not go back. left and right will transport you directly to the princess or the monster. Good Luck!" << "Enter your command:Go ";
    // There are two portals that directly into the princess or monster
}
