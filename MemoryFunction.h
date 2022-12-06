#pragma once
#include <fstream>
#include "BasicFunction.h"

using namespace std;

class AllUser {
public:
	int getTopScore();
	int getUserAmount();
	string getUserName(int id);
	int getLanguage();
	void setLanguage(int lang);
	int check(string checkName);
	bool initialize();
	void signin(string newName);
private:
	void writeConfig();
	void writeConfig(string path);
	void writeSetting(int lang);
	void writeSetting(int lang, string path);
	int TopScore = 0,UserAmount = 0;
	int memLang = 0;
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
