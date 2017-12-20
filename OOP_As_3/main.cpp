//
//  main.cpp
//  oop3
//
//  Created by 张倬豪 on 2016/11/29.
//  Copyright © 2016年 Icarus. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "adventure.h"

using namespace std;

bool getP = false;
lobby lob;
basicRoom room1("room1");
basicRoom room2("room2");
basicRoom room3("room3");
basicRoom room4("room4");
basicRoom room5("room5");
basicRoom room6("room6");
portal por;

int main(int argc, const char * argv[]) {
    int princessRoomNum = ((rand() % 7) + 4) % 7;
    while (princessRoomNum == 0) princessRoomNum = rand() % 7;
    int monsterRoonNum = ((rand() % 7) + 6) % 7;
    while (monsterRoonNum == princessRoomNum || monsterRoonNum == 0) monsterRoonNum = rand() % 7;
    // Generate the room number of princess and monster
    
    buildCastle();
    // Create the castle
    
    setPM(princessRoomNum, monsterRoonNum);
    // Set the princess and the monster
    
    lob.showInfo();
    string direction;
    basicRoom* now = &lob;
    now->princess = now->monster = false;
    
    while (true) {
        cin >> direction;
        now = now->goNext(direction);
        now->showInfo();
        if (now->monster || (now->lobbyAgain && getP)) break;
        // If the user meets the monster or got the princess and gets out, break
    }
    
    return 0;
}
