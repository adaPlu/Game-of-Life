#ifndef GAMEOFLIFE
#define GAMEOFLIFE

#include <string>
#include <server.h>
#include <Cell.h>

class GameOfLife{
public:

	std::vector <std::vector<Cell>> board;
	int height;
	int width;
	
	GameOfLife();
	GameOfLife(int height, int width);
	
	void start();
	void stop();
	void advance();

	ucm::json getBoard() ;

};

#endif
