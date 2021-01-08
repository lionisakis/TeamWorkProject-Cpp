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
        string output="Choose your action.\n0) To quit.\n1) To see Info of heroes.\n3) To use an Item.\n5) To see the map.\n";
        output.append("\t8) To go Up.\n4) To go Left.\t\t6) To go Right.\n\t2) To go down.\n");
        int input = readNumber(output, 0, 8);
        if(input == 1)
            for(int i=0;i<hero.size();i++)
                hero.at(i)->print();
        if(input == 0)
            return;
        else if(input == 3)
            for(int i=0;i<hero.size();i++)
                hero.at(i)->useInventory();
        else if(input == 8)
            grid->print();
        else if(input == 8)
            grid->move(UP);
        else if(input == 2)
            grid->move(DOWN);
        else if(input == 4)
            grid->move(LEFT);
        else if(input == 6)
            grid->move(RIGHT);
        recoverMap(hero);
        grid->print();
    }
        
}