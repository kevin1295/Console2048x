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
int ERRORMSG(int errorCode);


struct gameMap {								// Only used for functions transportation
	short map[5][5] = {0};
	int step = 0, gameScore = -1, topScore = -1;
};

class ClassOfMessageBox {
public:
	void inputError();
	void memoryFull();
	bool continueGame();
	bool logout();
	bool interruptGame();
	bool saveProcess();
	bool signin();
private:
	int languageMod;
};
