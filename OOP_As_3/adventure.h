//
//  adventure.hpp
//  oop3
//
//  Created by 张倬豪 on 2016/11/29.
//  Copyright © 2016年 Icarus. All rights reserved.
//

#ifndef adventure_h
#define adventure_h

#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

class basicRoom {
public:
    basicRoom(const string& name):
        princess(false),
        monster(false),
        lobbyAgain(false),
        name(name)
    {};// Constructor
    basicRoom(const basicRoom& br); // Copy Ctor
    basicRoom();
    virtual void showInfo(); //Show the information of the room
    virtual basicRoom* goNext(const string &direction);
    virtual void setPrincess(){princess = true;}
    virtual void setMonster(){monster = true;}
    map<string, basicRoom*> exits;
    virtual ~basicRoom(){};
    bool princess;
    bool monster;
    bool lobbyAgain;
private:
    string name;
};

void setPM(int princessRoomNum, int monsterRoomNum);

void buildCastle();

class lobby: public basicRoom {//lobby of the castle
public:
    lobby();
    void showInfo();
    virtual ~lobby() = default;
};

class portal: public basicRoom {
public:
    portal();
    void showInfo();
    virtual ~portal() = default;
};
#endif /* adventure_hpp */
