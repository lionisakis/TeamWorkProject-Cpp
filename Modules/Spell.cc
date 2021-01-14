#include "Spell.h"
#include <cstdlib>

Spell::Spell(string name_init, int price_init, int level_init, int damage_up_init, int damage_down_init, int magic_power_init){
    this->name = name_init;
    this->price = price_init;
    this->level = level_init;
    this->damage_up = damage_up_init;
    this->damage_down = damage_down_init;
    this->magicPower = magic_power_init;
    this->type = "None";
    this->doge = 25;
}

Spell::~Spell(){
}

string Spell::getName(void)const{
    return this->name;
}

int Spell::getPrice(void)const{
    return this->price;
}

int Spell::getLevel(void)const{
    return this->level;
}

int Spell::getMagicPower(void)const{
    return this->magicPower;
}

int Spell::getDamage(Hero* hero)const{
    //decrease the damages rage and return a random amount of damage
    int magicPower = hero->getMP();
    hero->useMagicPower(this->getMagicPower());
    int dexterity = hero->getDexterity();
    srand(time(NULL));
    int temp_down = this->damage_up;
    int prob = rand() % (temp_down + 1);
    while(prob <= doge){
        temp_down += 10;
        prob = rand() % (temp_down + 1);
    }
    if(temp_down > this->damage_up)
        temp_down = this->damage_up / 2;
    int damage = (this->damage_up + this->damage_down) / 2;
    while(damage < temp_down){
        damage = rand() % (this->damage_up + 1);
    }
    return damage;
}

string Spell::getType(void)const{
    return this->type;
}

void Spell::setType(string type){
    this->type = type;
}

void Spell::printCombat(void)const{
    cout << "Name: " << this->name <<", Level: " << this->level <<", Magic Cost:"<<getMagicPower()<<", Damage Range: ("<<damage_down<<","<<damage_up<<"), Type:"<<getType()<< endl;
}

void Spell::print(void)const{
    cout << "Name: " << this->name << ", Price: " <<this->getPrice()<<", Level: " << this->level <<", Damage Range: ("<<damage_down<<","<<damage_up<<"), Type:"<<getType()<< endl;
}
