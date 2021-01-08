#include "Grid.h"

Grid::Grid(vector<Hero*> heroes, Util util){
    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            int name = rand() % 3;
            if(name == 0)
                grid[i][j].setName("C");
            else if(name==1)
                grid[i][j].setName("M");
            else
                grid[i][j].setName("N");
        }
    }
    grid[0][0].setName("C");
    this->market = new Market(util);
    this->heroes = heroes;
    i_heroes = 0;
    j_heroes = 0;
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
    if(dest == DOWN){
        i = this->i_heroes + 1;
        j = this->j_heroes;
    }
    if(dest == RIGHT){
        i = this->i_heroes;
        j = this->j_heroes + 1;
    }
    if(dest == LEFT){
        i = this->i_heroes;
        j = this->j_heroes - 1;
    }
    if(this->grid[i][j].getName() == N){
        cout << "This block is non accessible" << endl;
        return;
    }
    else{
        cout << i << j << endl;
        this->grid[i][j].move(this->heroes);
        this->grid[i_heroes][j_heroes].clear();
        i_heroes = i;
        j_heroes = j;
    }
}

void Grid::place(void){
    this->grid[0][0].move(this->heroes);
}