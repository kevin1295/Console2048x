#pragma once
#include <fstream>
#include "BasicFunction.h"

using namespace std;

class AllUser {
public:
	int getTopScore();
	int getUserAmount();
	string getUserName(int id);
	int check(string checkName);
	bool initialize();
	void signin(string newName);
private:
	void write();
	int TopScore = 0,UserAmount = 0;
	string name[17];
};

class oneUser {
public:
	gameMap readMap();
	string getPlayerName();
	int getPlayerID();

	void signin(int id, string name);
	void setPlayer(int id, string name);
	void write(gameMap staffs);
private:
	int currentPlayerID = 0;
	string currentPlayerName;
};
