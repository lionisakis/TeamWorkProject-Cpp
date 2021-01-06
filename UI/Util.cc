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

string takeRandomName(vector<string> item){
    srand(time(NULL));
    return item.at(rand()%item.size());
}

string Util::randomName(int indexType) {
    if (indexType==DRAGON)
        return takeRandomName(namesLiving);
    else if (indexType==EXOSKELETON)
        return takeRandomName(namesLiving);
    else if (indexType==SPIRIT)
        return takeRandomName(namesLiving);
    else if (indexType==ARMOR)
        return takeRandomName(namesArmor);
    else if (indexType==POTION)
        return takeRandomName(namesPotion);
    else if (indexType==WEAPON)
        return takeRandomName(namesWeapon);
    else if (indexType==LIGHTINGSPELL)
        return takeRandomName(namesSpell);
    else if (indexType==FIRESPELL)
        return takeRandomName(namesSpell);
    else if (indexType==ICESPELL)
        return takeRandomName(namesSpell);
    cout<<"PROBLEM\n";
    return "PROBLEM";
}

Monster* Util::spawnMonster(int indexType,int levelHero){
    if (indexType==DRAGON)
        return spawnDragon(levelHero);
    else if (indexType==EXOSKELETON)
        return spawnExoskeleton(levelHero);
    else if (indexType==SPIRIT)
        return spawnSpirit(levelHero);
    cout<<"PROBLEM\n";
    return NULL;
}
Monster* Util::spawnDragon(int levelHero){
    return (Monster*) new Dragon(randomName(DRAGON),levelHero);
}
Monster* Util::spawnExoskeleton(int levelHero){
    return (Monster*) new Exoskeleton(randomName(EXOSKELETON),levelHero);
}
Monster* Util::spawnSpirit(int levelHero){
    return (Monster*) new Spirit(randomName(SPIRIT),levelHero);
}

Item* Util::spawnItem(int indexType,int price , int level , int  damage_defence_use,int hands_amount,bool available){
    if (indexType==ARMOR)
        return spawnArmor(price,level,damage_defence_use);
    else if (indexType==POTION)
        return spawnPotion(price ,level ,damage_defence_use,hands_amount,available);
    else if (indexType==WEAPON)
        return spawnWeapon(price,level,damage_defence_use,hands_amount);
    cout<<"PROBLEM\n";
    return NULL;
}
Item* Util::spawnArmor(int price , int level , int  defence){
    return (Item*) new Armor(randomName(ARMOR),price,level,defence);
}
Item* Util::spawnPotion(int price , int level , int  use,int amount,bool available){
    return (Item*) new Potion(randomName(POTION),price,level,use,amount,available);

}
Item* Util::spawnWeapon(int price , int level , int  damage,int hands){
    return (Item*) new Weapon(randomName(WEAPON),price,level,damage,hands);

}

Spell* Util::spawnSpell(int indexType, int price , int level , int decrease){
    if (indexType==LIGHTINGSPELL)
        return spawnLightingSpell(price,level,decrease);
    else if (indexType==FIRESPELL)
        return spawnFireSpell(price,level,decrease);
    else if (indexType==ICESPELL)
        return spawnIceSpell(price,level,decrease);
    cout<<"PROBLEM\n";
    return NULL;
}
Spell* Util::spawnLightingSpell(int price , int level , int decrease){
    return (Spell*) new LightingSpell(randomName(LIGHTINGSPELL),price,level,decrease);
}
Spell* Util::spawnFireSpell(int price , int level , int decrease){
    return (Spell*) new FireSpell(randomName(FIRESPELL),price,level,decrease);
}
Spell* Util::spawnIceSpell(int price , int level , int decrease){
    return (Spell*) new IceSpell(randomName(ICESPELL),price,level,decrease);

}