#include "Potion.h"

Potion::Potion(string name_init, int price_init, int level_init, int use_init, int amount_init, bool available_init):Item(name_init, price_init, level_init){
    this->use = use_init;
    this->amount = amount_init;
    this->available = available_init;
    cout << "A new potion with name: " << Item::getName() << " has been created" << endl; 
}

Potion::~Potion(){
    cout << "A potion with name: " << Item::getName() << " is about to be destroyed" << endl; 
}