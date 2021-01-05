IDIR = $(dir $(lastword $(MAKEFILE_LIST)))Include/
MDIR = $(dir $(lastword $(MAKEFILE_LIST)))Modules/

CXX = g++
CXXFLAGS = -g -Wall -MMD -I$(IDIR)

LIBS = -lm

Items = $(MDIR)Items.o $(MDIR)Weapon.o $(MDIR)Armor.o $(MDIR)Potion.o
Hero = $(MDIR)Living.o $(MDIR)Hero.o $(MDIR)Warrior.o $(MDIR)Sorcerer.o $(MDIR)Paladin.o
Monsters= $(MDIR)Living.o $(MDIR)Monster.o $(MDIR)Dragon.o $(MDIR)Exoskeleton.o $(MDIR)Spirit.o
Spells = $(MDIR)Spell.o $(MDIR)IceSpell.o $(MDIR)FireSpell.o $(MDIR)LightingSpell.o

OBJ = main.o $(Items) $(Hero) $(Monsters) $(Spells)

EXEC= main

Itemsd = $(MDIR)Items.d $(MDIR)Weapon.d $(MDIR)Armor.d $(MDIR)Potion.d
Herod = $(MDIR)Living.d $(MDIR)Hero.d $(MDIR)Warrior.d $(MDIR)Sorcerer.d $(MDIR)Paladin.d
Monstersd = $(MDIR)Living.d $(MDIR)Monster.d $(MDIR)Dragon.d $(MDIR)Exoskeleton.d $(MDIR)Spirit.d
Spellsd = $(MDIR)Spell.d $(MDIR)IceSpell.d $(MDIR)FireSpell.d $(MDIR)LightingSpell.d


D= main.d $(Itemsd) $(Herod) $(Monstersd) $(Spellsd)

ARGS = 

$(EXEC)/%.o: %.c $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

run: $(OBJ)
	$(CXX) -o $(EXEC) $^ $(CXXFLAGS) $(LIBS)
	./$(EXEC) $(ARGS)

.PHONY: clean

clean:
	rm -f $(OBJ) $(EXEC) $(D)

valgrind: $(OBJ)
	$(CXX) -o $(EXEC) $^ $(CXXFLAGS) $(LIBS)
	valgrind ./$(EXEC) $(ARGS)
