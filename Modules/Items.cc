#include "../Include/Items.h"

Item::Item(string name_init, int price_init, int level_init){
    this->name = name_init;
    this->price = price_init;
    this->level = level_init;
    cout << "A new item with name: " << this->name << " has been created" << endl;
}

Item::~Item(){
    cout << "An item with name: " << this->name << " is about to be destroyed" << endl;
}