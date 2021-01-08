#include <iostream>
#include <vector>
using namespace std;

#include "UI.h"

void PlayGame(Util util, vector<Hero*> hero){
    cout << "Welcome to the game. " << endl;
    cout << "Press 1 to continue or 0 to exit. " << endl;
    int index = readNumber("", 0, 1);
    if(index == 0){
        quitGame(hero);
    }
    if(index == 1){
        Grid* grid = new Grid(hero, util);
        cout << "A new map has been created for you." << endl;
        while (true){
            cout << "Choose your move." << endl;
            cout << "Press 1 for up." << endl;
            cout << "Press 2 for down." << endl;
            cout << "Press 3 for left." << endl;
            cout << "Press 4 for right." << endl;
            cout << "Press 0 to quit." << endl;
            int input = readNumber("", 0, 4);
            if(input == 0)
                return;
            else if(input == 1)
                grid->move(UP);
            else if(input == 2)
                grid->move(DOWN);
            else if(input == 3)
                grid->move(LEFT);
            if(input == 4)
                grid->move(RIGHT);
            grid->print();
        }
        
    }
}