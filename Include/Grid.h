#pragma once

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
        Block grid[K][K];
        vector<Hero*> heroes;
        int i_heroes;
        int j_heroes;
        int probability;
        Util util;
    public:
        Grid(vector<Hero*>, Util);
        void print(void) const;
        void move(string);
        void place(int, int);
};