IDIR =$(dir $(lastword $(MAKEFILE_LIST)))include
MDIR =$(dir $(lastword $(MAKEFILE_LIST)))modules/

CXX=g++
CXXFLAGS= -g -Wall -MMD -I$(IDIR)

LIBS=-lm

OBJ = 

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
