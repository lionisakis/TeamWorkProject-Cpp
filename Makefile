IDIR = $(dir $(lastword $(MAKEFILE_LIST)))Include/
MDIR = $(dir $(lastword $(MAKEFILE_LIST)))Modules/
UDIR = $(dir $(lastword $(MAKEFILE_LIST)))UI/

CXX = g++
CXXFLAGS = -g -MMD -I$(IDIR)

LIBS = -lm

Items = $(MDIR)Items.o $(MDIR)Weapon.o $(MDIR)Armor.o $(MDIR)Potion.o
Hero = $(MDIR)Living.o $(MDIR)Hero.o $(MDIR)Warrior.o $(MDIR)Sorcerer.o $(MDIR)Paladin.o
Monsters= $(MDIR)Living.o $(MDIR)Monster.o $(MDIR)Dragon.o $(MDIR)Exoskeleton.o $(MDIR)Spirit.o
Spells = $(MDIR)Spell.o $(MDIR)IceSpell.o $(MDIR)FireSpell.o $(MDIR)LightingSpell.o
UI= $(UDIR)Fight.o $(UDIR)Util.o $(UDIR)Market.o $(UDIR)HerosFunction.o $(UDIR)Block.o $(UDIR)Grid.o $(UDIR)PlayGame.o

OBJ = main.o $(Items) $(Hero) $(Monsters) $(Spells) $(UI)

EXEC= main

Itemsd = $(MDIR)Items.d $(MDIR)Weapon.d $(MDIR)Armor.d $(MDIR)Potion.d
Herod = $(MDIR)Living.d $(MDIR)Hero.d $(MDIR)Warrior.d $(MDIR)Sorcerer.d $(MDIR)Paladin.d
Monstersd = $(MDIR)Living.d $(MDIR)Monster.d $(MDIR)Dragon.d $(MDIR)Exoskeleton.d $(MDIR)Spirit.d
Spellsd = $(MDIR)Spell.d $(MDIR)IceSpell.d $(MDIR)FireSpell.d $(MDIR)LightingSpell.d
UId= $(UDIR)Fight.d $(UDIR)Util.d $(UDIR)Market.d $(UDIR)HerosFunction.d $(UDIR)Block.d $(UDIR)Grid.d $(UDIR)PlayGame.d

D= main.d $(Itemsd) $(Herod) $(Monstersd) $(Spellsd) $(UId)

# ARGS = 

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
	valgrind --leak-check=full  ./$(EXEC) $(ARGS)
