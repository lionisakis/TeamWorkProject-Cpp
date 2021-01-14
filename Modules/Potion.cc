#include "Potion.h"

Potion::Potion(string name_init, int price_init, int level_init, string use_init, int amount_init, bool available_init):Item(name_init, price_init, level_init){
    this->usefull = use_init;
    this->amount = amount_init;
    this->available = available_init;
    Item::setType(POTION);
}

string Potion::getUsefull(void)const{;
    return this->usefull;
}

int Potion::getAmount(void)const{
    return this->amount;
}

bool Potion::getAvailable(void)const{
    return this->available;
}

void Potion::printInfo(void)const{
    Item::print();
    cout << "Amount of increasment: " << this->amount << endl;
}

bool Potion::use(Hero* hero){
    //if the hero is in smaller level than the potion's requirments or the potion has already be used it can not use it.
    if(hero->getLevel() < this->getLevel()){
        cout << "Hero needs to be in a higher level to use that spell" << endl;
        return false;
    }
    if(this->available == false){
        cout << "This potion has already be used" << endl;
        return false;
    }
    string type = this->getUsefull();
    int amount = this->getAmount();
    this->available = false;
    cout<<"Hero "<<hero->getName()<<" used "<<getName()<<"\n";
    hero->addToStat(type, amount);
    return true;
}