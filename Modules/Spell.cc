#include "Spell.h"
#include <cstdlib>

Spell::Spell(string name_init, int price_init, int level_init, int damage_up_init, int damage_down_init, int magic_power_init){
    this->name = name_init;
    this->price = price_init;
    this->level = level_init;
    this->damage_up = damage_up_init;
    this->damage_down = damage_down_init;
    this->magicPower = magic_power_init;
    this->type = 0;
    this->doge = 150;
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

int Spell::getDamage(int dexterity){
    srand(time(NULL));
    int temp_down = this->damage_up;
    int prob = rand() % (temp_down + 1);
    while(prob <= doge){
        temp_down += 10;
        prob = rand() % (temp_down + 1);
    }
    int damage;
    while(damage < temp_down){
        damage = rand() % (this->damage_up + 1);
    }
    return damage;
}

int Spell::getType(void){
    return this->type;
}

void Spell::setType(int type){
    this->type = type;
}

void Spell::print(void){
    cout << "Name: " << this->name << ", Price: " << this->price << ", Level: " << this->level << endl;
}