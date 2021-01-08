#include <iostream>
#include <cstring>
#include <vector>
#include <stdlib.h>
using namespace std;

#include "Define.h"
#include "Market.h"
#include "Block.h"
#include "Util.h"
#include "UI.h"

#pragma once

class Grid{
    private:
        Block grid[10][10];
        Market* market;
        vector<Hero*> heroes;
        int i_heroes;
        int j_heroes;
        int probability;
        Util util;
    public:
        Grid(vector<Hero*>, Util);
        void print(void);
        void move(string);
        void place(void);
};