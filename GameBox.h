// GamwBox.h
#pragma once

/*
* 
* This head is written to realize several operations on the blocks
* including turning the blocks aside
* and add a random block
* also the class covers the storage
* 
*/

#include <string>
#include "BasicFunction.h"
using namespace std;

struct block_box {
	short _int = 0;
	// The number on the block

	bool _bool = false;
	// Whether the block brings out score in the step
};
struct PBI {
	// A structure similiar to pair<bool,int>

	bool _bool = false;
	int _int = 0;
};

class GameBox {
public:
	block_box blocks[5][5];
	// This vari is used to store the present map

	short history[65536][5][5] = {0};	// For ctrl+Z and record for AI
	int pStep = 0;
	// This part is used for analysis and AI go back

	void initialize(int historyTop);
	void setBlocks(gameMap sourse);
	// Randomly generate two blocks

	void bonus(int addScore);

	PBI up();
	PBI down();
	PBI left();
	PBI right();

	bool checkStatement();

	void addBlock();
	// Randomly add a block in the map

	int getScore();
	int getTopScore();
	string getUserName();
	void setUserName(string name);
	gameMap getMap();
private:
	int historyTopScore = 0;
	string userName;
	int score = 0;
	void copy();
	int iCopy = 0, jCopy = 0;
	block_box blocksCopy[5][5];
};
