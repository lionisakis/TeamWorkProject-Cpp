#include "Spell.h"
#include <cstdlib>

Spell::Spell(string name_init, int price_init, int level_init, int damage_up_init, int damage_down_init, int health_init){
    this->name = name_init;
    this->price = price_init;
    this->level = level_init;
    this->damage_up = damage_up_init;
    this->damage_down = damage_down_init;
    this->health = health_init;
    this->type = 0;
    // cout << "A new item with name: " << this->name << " has been created" << endl;
}

Spell::~Spell(){
    // cout << "An item with name: " << this->name << " is about to be destroyed" << endl;
}

string Spell::getName(void){
    return this->name;
}

int Spell::getPrice(void){
    return this->price;
}

int Spell::getLevel(void){
    return this->level;
}

int Spell::getMagicPower(void){
    return this->magicPower;
}

int Spell::getDamage(void){
    srand(time(NULL));
    int damage = rand() % (this->damage_up + 1);
    while(damage < this->damage_down){
        damage = rand() % (this->damage_up + 1);
    }
    return damage;
}

int getType(void){
    return this->type;
}

void setType(int type){
    this->type = type;
}