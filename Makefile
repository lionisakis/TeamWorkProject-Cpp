IDIR = $(dir $(lastword $(MAKEFILE_LIST)))Include/
MDIR = $(dir $(lastword $(MAKEFILE_LIST)))Modules/

CXX = g++
CXXFLAGS = -g -Wall -MMD -I$(IDIR)

LIBS = -lm

Items = $(MDIR)Items.o $(MDIR)Weapon.o $(MDIR)Armor.o $(MDIR)Potion.o
Livings = $(MDIR)Living.o $(MDIR)Hero.o $(MDIR)Warrior.o $(MDIR)Sorcerer.o $(MDIR)Paladin.o
Spells = $(MDIR)Spell.o $(MDIR)IceSpell.o $(MDIR)FireSpell.o $(MDIR)LightingSpell.o

OBJ = main.o $(Items) $(Livings) $(Spells)

EXEC= main

ARGS = 

$(EXEC)/%.o: %.c $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

run: $(OBJ)
	$(CXX) -o $(EXEC) $^ $(CXXFLAGS) $(LIBS)
	./$(EXEC) $(ARGS)

.PHONY: clean

clean:
	rm -f $(OBJ) $(EXEC) 

valgrind: $(OBJ)
	$(CXX) -o $(EXEC) $^ $(CXXFLAGS) $(LIBS)
	valgrind ./$(EXEC) $(ARGS)
