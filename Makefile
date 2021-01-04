IDIR =$(dir $(lastword $(MAKEFILE_LIST)))Include/
MDIR =$(dir $(lastword $(MAKEFILE_LIST)))Modules/

CXX=g++
CXXFLAGS= -g -Wall -MMD -I$(IDIR)

LIBS=-lm

OBJ = main.o $(MDIR)Items.o $(MDIR)Weapon.o $(MDIR)Armor.o

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
