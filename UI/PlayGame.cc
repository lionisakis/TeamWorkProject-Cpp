#include <iostream>
#include <vector>
using namespace std;

#include "UI.h"

void PlayGame(Util util, vector<Hero*> hero){
    cout << "Welcome to the game. " << endl;
    Grid* grid = new Grid(hero, util);
    cout << "A new map has been created for you." << endl;
    grid->print();
    while (true){
        string output="Choose your action.\n0) To quit.\n1) To see Info of heroes.\n2) To use an Item. \n3) To go down. \n4) To see the map. \n5) To go Left. \n6) To go Right.\n";
        output.append("7) To go Right.\n8) To go Up.\n");
        int input = readNumber(output, 0, 8);
        if(input == 1)
            for(int i=0;i<hero.size();i++)
                hero.at(i)->print();
        if(input == 0)
            return;
        else if(input == 2)
            for(int i=0;i<hero.size();i++)
                hero.at(i)->useInventory();
        else if(input == 5)
            grid->print();
        else if(input == 7)
            grid->move(UP);
        else if(input == 3)
            grid->move(DOWN);
        else if(input == 4)
            grid->move(LEFT);
        else if(input == 6)
            grid->move(RIGHT);
        recoverMap(hero);
        grid->print();
    }
        
}