#include "Grid.h"

Grid::Grid(vector<Hero*> heroes, Util util){
    srand(time(NULL));
    for(int i = 0; i < K; i++){
        for(int j = 0; j < K; j++){
            int name = rand() % 3;
            if(name == 0)
                grid[i][j].setName(C);
            else if(name==1){
                int pos = rand() % 3;
                if(pos == 0 || pos == 1)        
                    grid[i][j].setName(M);
                else
                    grid[i][j].setName(C); 
            }
            else{
                int pos = rand() % 2;
                if(pos == 0)        
                    grid[i][j].setName(N);
                else
                    grid[i][j].setName(C);
            }
        }
    }
    int i_temp = rand() % K;
    int j_temp = rand() % K;
    grid[i_temp][j_temp].setName(C);
    this->heroes = heroes;
    this->i_heroes = i_temp;
    this->j_heroes = j_temp;
    this->probability = 40;
    this->util = util;
    // this->place(i_temp, j_temp);
    if(grid[i_heroes - 1][j_heroes - 1].getName() == N || grid[i_heroes - 1][j_heroes + 1].getName() == N || grid[i_heroes + 1][j_heroes - 1].getName() == N || grid[i_heroes + 1][j_heroes + 1].getName() == N){
        i_heroes = rand() % K;
        j_heroes = rand() % K;
        while(grid[i_heroes][j_heroes].getName() == N){
            i_heroes = rand() % K;
            j_heroes = rand() % K;      
        }
    }
    this->place(i_heroes, j_heroes);
}

void Grid::print(void) const{
    int lim_i_up = i_heroes - 5;
    int lim_i_down = i_heroes + 5;
    int lim_j_up = j_heroes - 5;
    int lim_j_down = j_heroes + 5;

    if(lim_i_up < 0)
        lim_i_up = 0;
    if(lim_j_up < 0)
        lim_j_up = 0;
    if(lim_i_down >= K)
        lim_i_down = K - 1;
    if(lim_j_down >= K)
        lim_j_down = K -1;

    for(int i = lim_i_up; i < lim_i_down; i++){
        for(int j = lim_j_up; j < lim_j_down; j++){
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
    if(i < 0 || i >= K || j < 0 || j >= K){
        cout << "This action will lead you out of the grid. ERROR." << endl;
        return;
    }
    if(this->grid[i][j].getName() == N){
        cout << "This block is non accessible" << endl;
        cout << "Please try another direction" << endl;
        return;
    }
    else{
        this->grid[i][j].move(this->heroes);
        this->grid[i_heroes][j_heroes].clear();
        i_heroes = i;
        j_heroes = j;
    }
    if(this->grid[i_heroes][j_heroes].getName() == M){
        cout << "Market" << endl;
        int index = readNumber("You are on a market do you want to use it?\n1)Yes.\n2)No.\n", 1, 2);
        if(index == 1){
            Market* market = new Market(util,MOOfLevelOfHeros(this->heroes));
            cout << "You have to enter the market one by one due to covid-19." << endl;
            for(int i = 0; i < this->heroes.size(); i++)
                market->useMarket(this->heroes.at(i));
            delete market;
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

void Grid::place(int i_temp, int j_temp){
    this->grid[i_temp][j_temp].move(this->heroes);
}