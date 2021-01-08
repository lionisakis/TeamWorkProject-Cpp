#include "Grid.h"

Grid::Grid(vector<Hero*> heroes, Util util){
    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            int name = rand() % 3;
            if(name == 0)
                grid[i][j].setName(C);
            else if(name==1)
                grid[i][j].setName(M);
            else
                grid[i][j].setName(N);
        }
    }
    grid[0][0].setName(C);
    this->market = new Market(util);
    this->heroes = heroes;
    this->i_heroes = 0;
    this->j_heroes = 0;
    this->probability = 40;
    this->util = util;
    this->place();
}

void Grid::print(void){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << this->grid[i][j].getName();
            if(grid[i][j].getSize())
                cout << "/H";
            cout<< "\t";
        }
        cout << endl;
    }
}

void Grid::move(string dest){
    int i, j;
    if(dest == UP){
        i = this->i_heroes - 1;
        j = this->j_heroes;
    }
    else if(dest == DOWN){
        i = this->i_heroes + 1;
        j = this->j_heroes;
    }
    else if(dest == RIGHT){
        i = this->i_heroes;
        j = this->j_heroes + 1;
    }
    else if(dest == LEFT){
        i = this->i_heroes;
        j = this->j_heroes - 1;
    }
    if(i < 0 || i >= 10 || j < 0 || j >=10){
        cout << "This action will lead you out of the grid. ERROR." << endl;
        return;
    }
    if(this->grid[i][j].getName() == N){
        cout << "This block is non accessible" << endl;
    }
    else{
        this->grid[i][j].move(this->heroes);
        this->grid[i_heroes][j_heroes].clear();
        i_heroes = i;
        j_heroes = j;
    }
    if(this->grid[i_heroes][j_heroes].getName() == M){
        cout << "Market" << endl;
        cout << "You are on market do you want to use it? Press 1 for Yes and 2 for No" << endl;
        int index = readNumber("", 1, 2);
        if(index == 1){
            cout << "You have to enter the market one by one due to covid-19." << endl;
            for(int i = 0; i < this->heroes.size(); i++)
                this->market->useMarket(this->heroes.at(i));
        }
        else
            return;
    }
    else if(this->grid[i_heroes][j_heroes].getName() == C){
        cout << "Common" << endl;
        int fight_prob = rand() % 100;
        if(fight_prob > this->probability){
            cout << "Heroes you have entered a fight." << endl;
            battle(this->heroes, this->util);
        }

    }
}

void Grid::place(void){
    this->grid[0][0].move(this->heroes);
}