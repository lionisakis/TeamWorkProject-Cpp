#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "Util.h"
#include "Define.h"
#include <string>
using namespace std;

#include "Dragon.h"
#include "Exoskeleton.h"
#include "Spirit.h"

#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"

#include "FireSpell.h"
#include "IceSpell.h"
#include "LightingSpell.h"


Util::Util(){
    string txt;
    string path=PATH;
    path.append("names.txt");
    ifstream namesLivingFile(path);

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(namesLivingFile,txt)) {
        namesLiving.push_back(txt);
    }

    path=PATH;
    path.append("armors.txt");
    ifstream namesArmorsFile(path);

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(namesArmorsFile,txt)) {
        namesArmor.push_back(txt);
    }

    path=PATH;
    path.append("potions.txt");
    ifstream namesPotionFile(path);

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(namesPotionFile,txt)) {
        namesPotion.push_back(txt);
    }

    path=PATH;
    path.append("weapons.txt");
    ifstream namesWeaponFile(path);

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(namesWeaponFile,txt)) {
        namesWeapon.push_back(txt);
    }

    path=PATH;
    path.append("spells.txt");
    ifstream namesSpellFile(path);

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(namesSpellFile,txt)) {
        namesSpell.push_back(txt);
    }

    // Close the file
    namesSpellFile.close();
    namesWeaponFile.close();
    namesPotionFile.close();
    namesArmorsFile.close();
    namesLivingFile.close();
}

bool Util::checkTheNumber(int number,vector<string> item,int vec){
    for(int i=0;i<previous[vec].size();i++)
        if(number==previous[vec].at(i))
            return false;
    if(previous[vec].size()==item.size()/2)
        previous[vec].clear();
    return true;
}

string Util::takeRandomName(vector<string> item,int vec){
    int i;
    do{
        i=rand()%item.size();
    }while(!checkTheNumber(i,item,vec));
    previous[vec].push_back(i);
    return item.at(i);
}

string Util::randomName(string indexType) {
    if (indexType==DRAGON)
        return takeRandomName(namesLiving,0);
    else if (indexType==EXOSKELETON)
        return takeRandomName(namesLiving,0);
    else if (indexType==SPIRIT)
        return takeRandomName(namesLiving,0);
    else if (indexType==ARMOR)
        return takeRandomName(namesArmor,1);
    else if (indexType==POTION)
        return takeRandomName(namesPotion,2);
    else if (indexType==WEAPON)
        return takeRandomName(namesWeapon,3);
    else if (indexType==LIGHTINGSPELL)
        return takeRandomName(namesSpell,4);
    else if (indexType==FIRESPELL)
        return takeRandomName(namesSpell,4);
    else if (indexType==ICESPELL)
        return takeRandomName(namesSpell,4);
    cout<<"PROBLEM1\n";
    return "PROBLEM";
}

// Monster* Util::spawnMonster(string indexType,int levelHero){
//     if (indexType==DRAGON)
//         return spawnDragon(levelHero);
//     else if (indexType==EXOSKELETON)
//         return spawnExoskeleton(levelHero);
//     else if (indexType==SPIRIT)
//         return spawnSpirit(levelHero);
//     cout<<"PROBLEM2\n";
//     return NULL;
// }
Monster* Util::spawnDragon(int levelHero){
    return new Dragon(randomName(DRAGON),levelHero);
}
Monster* Util::spawnExoskeleton(int levelHero){
    return new Exoskeleton(randomName(EXOSKELETON),levelHero);
}
Monster* Util::spawnSpirit(int levelHero){
    return new Spirit(randomName(SPIRIT),levelHero);
}

// Item* Util::spawnItem(string indexType,int price , int level , int  damage_defence_use,int hands_amount,bool available){
//     if (indexType==ARMOR)
//         return spawnArmor(price,level,damage_defence_use);
//     else if (indexType==POTION)
//         return spawnPotion(price ,level ,damage_defence_use,hands_amount,available);
//     else if (indexType==WEAPON)
//         return spawnWeapon(price,level,damage_defence_use,hands_amount);
//     cout<<"PROBLEM3\n";
//     return NULL;
// }
Item* Util::spawnArmor(int price , int level , int  defence){
    return new Armor(randomName(ARMOR),price,level,defence);
}
Item* Util::spawnPotion(int price , int level , string  use,int amount,bool available){
    return new Potion(randomName(POTION),price,level,use,amount,available);
}
Item* Util::spawnWeapon(int price , int level , int  damage,int hands){
    return new Weapon(randomName(WEAPON),price,level,damage,hands);

}

// Spell* Util::spawnSpell(string indexType, int price , int level , int decrease){
//     if (indexType==LIGHTINGSPELL)
//         return spawnLightingSpell(price,level,decrease);
//     else if (indexType==FIRESPELL)
//         return spawnFireSpell(price,level,decrease);
//     else if (indexType==ICESPELL)
//         return spawnIceSpell(price,level,decrease);
//     cout<<"PROBLEM4\n";
//     return NULL;
// }
Spell* Util::spawnLightingSpell(int price , int level , int decrease, int damage_up, int damage_down, int magic_power){
    return new LightingSpell(randomName(LIGHTINGSPELL),price,level,decrease, damage_up, damage_down, magic_power);
}
Spell* Util::spawnFireSpell(int price , int level , int decrease, int damage_up, int damage_down, int magic_power){
    return new FireSpell(randomName(FIRESPELL),price,level,decrease, damage_up, damage_down, magic_power);
}
Spell* Util::spawnIceSpell(int price , int level , int decrease, int damage_up, int damage_down, int magic_power){
    return new IceSpell(randomName(ICESPELL),price,level,decrease, damage_up, damage_down, magic_power);

}