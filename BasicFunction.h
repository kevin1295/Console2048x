// BasicFunction.h
#pragma once

/*
* 
* This head is written to realize some functions for the general project
* including 
* key press detect
* messagebox
* 
*/

int keyPress();
void NEEDSDEVELOP();


struct gameMap {								// Only used for functions transportation
	short map[5][5] = {0};
	int step = 0, gameScore = -1, topScore = -1;
};

class ClassOfMessageBox {
public:
	void inputError();
	bool logout();
private:
	int languageMod;
};
