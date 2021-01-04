#include "Include/Items.h"
#include "Include/Weapon.h"
#include "Include/Armor.h"

int main(void){
    Armor* item = new Armor("Sward", 4, 2, 1000);
    delete item;
}