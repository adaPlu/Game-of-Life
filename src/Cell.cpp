#include <Cell.h>

Cell::Cell(){
        alive = false;
}

Cell::Cell(bool state){
        alive = state;
}

void Cell::makeAlive() {
    alive = true;
}

void Cell::makeDead() {
    alive = false;
}

int Cell::countNeighbors(std::vector <std::vector<Cell>> board, int i, int j){
        int neighbors = 0;
	for(int k = -1; k <= 1; k++){
	        for(int l = -1; l <= 1; l++){
			if(board[i + k][j + l].alive ){
			        neighbors++;
			}
		}
	}
        return neighbors;
}

