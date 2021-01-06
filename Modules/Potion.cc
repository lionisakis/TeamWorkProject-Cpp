#include "Potion.h"

Potion::Potion(string name_init, int price_init, int level_init, string use_init, int amount_init, bool available_init):Item(name_init, price_init, level_init){
    this->type = use_init;
    this->amount = amount_init;
    this->available = available_init;
    Item::setType(POTION);
}

Potion::~Potion(){
}

string Potion::getUse(void){
    return this->type;
}

int Potion::getAmount(void){
    return this->amount;
}

bool Potion::getAvailable(void){
    return this->available;
}

void Potion::printInfo(void){
    Item::print();
    cout << "Amount of increasment: " << this->amount << endl;
}

void Potion::use(Hero* hero){
    if(hero->getLevel() < this->getLevel()){
        cout << "Hero needs to be in a higher level to use that spell" << endl;
        return;
    }
    if(this->available == false){
        cout << "This potion has already be used" << endl;
        return;
    }
    string type = this->getUse();
    int amount = this->getAmount();
    this->available = false;
    hero->addToStat(type, amount);
}