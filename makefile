CXX = g++
EXEC = tetrisclassic
SRC = tetris.cpp main.cpp

all : $(EXEC)

$(EXEC) : $(SRC)
	$(CXX) $(SRC) -o $(EXEC) -Wall -Wextra