#pragma once
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include "UI.h"
#include "Util.h"
#include "Monster.h"
#include "Hero.h"
#include "Grid.h"
#include "Define.h"

using namespace std;

#include "Hero.h"

bool battle(vector<Hero*> heros,Util util);
void quitGame(vector<Hero*> heros);
vector<Hero*> spawnHeros();
int readNumber(string output,int down,int up);
int MOOfLevelOfHeros(vector<Hero*> heros);
void PlayGame(Util util, vector<Hero*> hero);