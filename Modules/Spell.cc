#include "Spell.h"

Spell::Spell(string name_init, int price_init, int level_init, int damage_up_init, int damage_down_init, int health_init){
    this->name = name_init;
    this->price = price_init;
    this->level = level_init;
    this->damage_up = damage_up_init;
    this->damage_down = damage_down_init;
    this->health = health_init;
    // cout << "A new item with name: " << this->name << " has been created" << endl;
}

Spell::~Spell(){
    // cout << "An item with name: " << this->name << " is about to be destroyed" << endl;
}

string Spell::getName(){
    return this->name;
}