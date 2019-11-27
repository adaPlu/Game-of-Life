#include <GameOfLife.h>
#include <iostream>
 
 using json = nlohmann::json;
//Default 5x5
GameOfLife::GameOfLife(){
	Cell setup;
	setup.alive = false;
	height = 6;
	width = 6;
	//Intialize all false board
	for(int i = 0; i <= height; i++){
		std::vector<Cell> inputV;
		for(int j = 0; j <= width; j++){
			inputV.push_back(setup);
		}
		board.push_back(inputV);	
	}
	//Intialize default blinker from lab code
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			
			if(i == 1 && (j == 0 || j == 1 ||  j == 2)){	
				board[i][j].makeAlive();
			}
			if(i == 4 && (j == 3 || j == 4 ||  j == 5)){	
				board[i][j].makeAlive();
			}
		}
	}
	
	
		
}

GameOfLife::GameOfLife(int height, int width){
	Cell setup;
	setup.alive = false;
	this->height = height;
	this->width = width;
	//Intialize all false board
	for(int i = 0; i < width; i++){
		std::vector<Cell> inputV;
		for(int j = 0; j < height; j++){
			 inputV.push_back(setup);		
		}
		board.push_back(inputV);	
	}
	
}


void GameOfLife::start(){
	
}

void GameOfLife::stop(){

}

//Updates Board State
void GameOfLife::advance(){

	//Create a temp copy of board
	std::vector <std::vector<Cell>> next = board;
	int neighbors = 0;
	int c = 0;

	//Count neighbors of each cell and update that cells state
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			//Counts Neighbors
			neighbors = 0;
			//Edge Cases
			//Top Edge
			
			//Bottom Edge
			
			//Left Edge
			
			//Right Edge
			
			//Corner Cases
			//Upper Left
			
			//Lower Right
			
			//Lower Left
			
			//Upper Right
			
			//Board Middle
			/*else*/
			if(i >= 1 && j >= 1){
				//Counts a cells neighbors
				neighbors = board[i][j].countNeighbors(board,i,j); 
			}
			
			//Subtract one for self if alive and has neighbors
			if(neighbors != 0 && board[i][j].alive)
				neighbors--;
	
			//Life Rules		
			//Any live cell with fewer than two live neighbours dies, as if by underpopulation
			if ((board[i][j].alive) && (neighbors < 2))
				next[i][j].makeDead();
			//Any live cell with more than three live neighbours dies, as if by overpopulation.
			else if ((board[i][j].alive) && (neighbors > 3))
				next[i][j].makeDead();
			//Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction. 
			else if (!(board[i][j].alive) && (neighbors == 3))
				next[i][j].makeAlive(); 
			//Any live cell with two or three live neighbours lives on to the next generation.
			else
				next[i][j] = board[i][j];
		}
	}
	
	
	//Update board to next state
	board = next;
}


//Returns Board State
ucm::json GameOfLife::getBoard() {
	ucm::json result;
	for(int i = 0; i < height; i++){
		std::vector<bool> array;
		for(int j = 0; j < width; j++){
			array.push_back(board[i][j].alive); 		
		}
		result.push_back(array);	
	}
	return result;
}


