#include "Items.h"
#include "Weapon.h"
#include "Armor.h"

#include "Paladin.h"
#include "Warrior.h"
#include "Sorcerer.h"


int main(void){
    Armor* item = new Armor("Sward", 4, 2, 1000);
    delete item;
    
    Paladin("Paladin");
    Warrior("Warrior");
    Sorcerer("Sorcerer");

}