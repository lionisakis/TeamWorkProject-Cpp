# Object Oriented Programming - Winter 2020-21 #
# Final Project in C++ #
---
Athors:
- Lionis Emmanouil Georgios(akis)
- Skevofylaka Maria

**There is a problem with Valgrind that sometimes does not work properly (it does not use "free" at space that its itself creates). It is not a problem with my code but it is a problem with the library Valgrind itself. It does not occur in all the computers but with those that have an old version of Valgrind. The issue that Valgrind itself told is at https://www.valgrind.org/docs/manual/faq.html#faq.reports  in the 4.1 section.**

## Compile and Execution Commands: ##
The project contains a Makefile which is responsible for the compilation and execution of the program. So:

- compile: make
- compile and execution: make run
- compile and valgrind: make valgrind

## Summary of the program: ##
The program simulates a game that creates a specific number of heroes and a map in which they travel. Every block of the map is a common block or a market block or a non accessible block in which heroes can not go. If the block is a common block heroes may fight with a specific probability or may not and just continue their adventure. If they fight they have to end the fight (by killing the monsters or by dying themselves) to move on the next block. If the block is a market block they can either use the market or leave. In case that they choose to use the market they can either buy or sell something. The game continues by the time the player press quit.

## Explanation of the files: ##
There are 3 folders (include,modules,UI), which helps organize the files. The include folder has all the necessary .h files. The modules folder has all the executes of the class that are an object of the world. The UI has the files that execute the world and how it creates the heroes, how the heroes move around, how the shop and how they fight.

## Explanation of the code: ##
The code has been  separated into 6 groups. The groups are Heroes, Monsters, Items, Spells, Market, Fight and Grid.

### Item ###
The class Item is a super-class which contains three sub-classes(Armor, Weapon, Potion).  The class Item describes a token the hero uses during the game in order to become stronger and defeat its enemies. The most important functions of the Item are the print and print combat functions that print the most important information about that Item such as their name, type, price etc.

### Spells ###
The class Spell is a super-class which contains three sub-classes(IceSpell, FireSpell, LightingSpell). This class simulates a spell used by the hero to increase a specific characteristic of its enemy. The two most important functions of the Spell class are: getDamage and printCombat. The getDamage function returns a “random” amount of damage that the hero causes to its enemy. The printCombat function works just like the Item’s printCombat function and prints the most important characteristics of the spell.

### Heroes ###
The class Heroes have a super-class Living which describes a living organism. Also, it has sub-classes for different types of Heroes (Paladin, Sorcerer, Warrior). The class hero has many functions which help it interact with the world. The most important are: buy (which buys an item or a spell), sell ( which sells an item or a spell), attack(which attacks a monster), castSpell ( which shows the user the spells with each spell to have a number. Then the User chooses a number and then that spell is being casted to a monster by using a helpful function spellCast), takeDamage (which sees if it doge the attack and sees how much damage it takes), useInventory( which shows the inventory with each item to have a number. Then the User chooses a number and then that item is being used by using a helpful function. It also has the ability to unequip an armor or a weapon.

### Monster ###
The class Monster has a super-class Living which describes a living organism. Also, it has sub-classes for different types of Monsters (Dragon, Spirit, Exoskeleton). The class Monster has the basic functions: attack(which attacks a random Hero), takeDamage (which sees if it dodges the attack and sees how much damage it takes).


### Market ###
The class Market simulates a shop in which heroes can buy and sell Items and Spells. This class contains many different functions. First of all its constructor function contains a new market with a random amount of spells and items available. The useMarket function shows up a menu that allows the hero to get some specific options. If the hero chooses to buy something, it sees the list of the available products and either buys or goes. If he buys something, it removes from the market’s list and is added to the hero's inventory. Also its money is decreased by the product’s price. On the other side if he chooses to sell something, that token is removed from its inventory and added to the store’s list. Also its money is increased by the product’s half price

### Fight ###
The file Fight has many functions that combined make the heroes fight monsters.
The functions are: createMonster (which creates a pack of random types of monster), checkAlive (which checks if all the heroes and the monsters are alive), checkAliveMonsters(which checks if the monsters are alive), checkAliveHeroes(which checks if the heroes are alive), restoreHP (which restores the hp of heroes and monsters), resotreMP (which restores the MP of the heroes), moveHero (which lets the user to choose a move of a hero), moveMonster (which all the monster attack random heroes), herosLose (which takes the half of the money of the heroes), heroWin (which gives money and experience to the heroes).  Finally, the function fight combines all the previous functions to simulate a fight.

### Grid ###
The class Grid simulates the map of the game. It contains an array of blocks which are common or market or non accessible. The grid is created by giving names to the different blocks and places the heroes to a specific block which makes sure it is common and it is not surrounded by non accessible blocks. Also the print function prints an 10*10 array around the heroes in order to save space. The move function takes as input a direction and moves the heroes to this specific block. 
