#ifndef CELL
#define CELL

#include <string>
#include <server.h>

class Cell {
public:
    //Variables
    bool alive;

    //Constructors
    Cell();
    Cell(bool alive);

    //Public Functions
    int countNeighbors(std::vector <std::vector<Cell>> board, int i, int j);
    void makeAlive();
    void makeDead();
    
};
#endif