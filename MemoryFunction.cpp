#include "MemoryFunction.h"
#include <time.h>
#include <io.h>

#define AllUserPath "user\\all\\config.memoryfile"
#define SettingPath "user\\all\\settings.memoryfile"

string playerPath = "user\\all\\";
ifstream fin;
ofstream fout;
bool error01 = false;
string s = "           ";

// ------------------------------- AllUser --------------------------------

void AllUser::writeConfig() {
	fout.open(AllUserPath, ios::binary | ios::ate);
	fout << "v0.1.1beta.1\n" << TopScore << endl << endl;
	fout << UserAmount << endl;
	for (int i = 1; i <= UserAmount; i++) {
		fout << name[i] << endl;
	}
	fout.close();
}

void AllUser::writeConfig(string path){
	fout.open(path.c_str(), ios::binary | ios::ate);
	fout << "v0.1.1beta.1\n" << TopScore << endl << endl;
	fout << UserAmount << endl;
	for (int i = 1; i <= UserAmount; i++) {
		fout << name[i] << endl;
	}
	fout.close();
}

void AllUser::writeSetting(int lang){
	fout.open(SettingPath, ios::binary | ios::ate);
	fout << "v0.1.1beta.1\n" << lang << endl;
	fout.close();
}

void AllUser::writeSetting(int lang, string path){
	fout.open(path.c_str(), ios::binary | ios::ate);
	fout << "v0.1.1beta.1\n" << lang << endl;
	fout.close();
}

int AllUser::getTopScore() { return TopScore; }

int AllUser::getUserAmount() { return UserAmount; }

string AllUser::getUserName(int id) { return name[id]; }

int AllUser::getLanguage() { return memLang; }

void AllUser::setLanguage(int lang){
	memLang = lang;
	writeSetting(lang);
}

int AllUser::check(string checkName) {	// get the id with an available name or a -1 with a name that wasn't in the record
	for (int i = 1; i <= UserAmount; i++) {
		if (checkName == name[i]) return i;
	}
	return -1;
}

bool AllUser::initialize() {

	// check access
	if ((_access(AllUserPath, 0)) == -1) {	// initialize record
		system("mkdir user\\all");
		fout.open(AllUserPath, ios::binary | ios::app);
		fout << "v0.1.1beta.1\n0\n\n0\n";
		fout.close();
		fout.open(SettingPath, ios::binary | ios::app);
		fout << "0.1.1beta.1\n0\n";
		fout.close();
		return false;
	}
	if ((_access(AllUserPath, 6)) == -1) {	// error! (6 represent read and write.)
		if (ERRORMSG(1) == 1) {
			error01 = true;
			return false;
		}
		else {
			exit(0);
		}
	}
	fin.open(AllUserPath, ios::binary | ios::in);
	fin >> s;	// skip a line
	fin >> TopScore;
	fin >> UserAmount;
	for (int i = 1; i <= UserAmount; i++) {
		fin >> name[i];
	}
	fin.close();
	fin.open(SettingPath, ios::binary | ios::in);
	fin >> s;	// skip a line
	fin >> memLang;
	fin.close();
	return true;
}

void AllUser::signin(string newName) {
	UserAmount++;
	name[UserAmount] = newName;
	string mkdir = "mkdir user\\" + newName;
	system(mkdir.c_str());
	playerPath = "user\\" + newName + "\\.memoryfile";
	fout.open(playerPath.c_str(), ios::binary | ios::ate);
	fout.close();
	
	writeConfig();
}

// -------------------------------- oneUser --------------------------------

gameMap oneUser::readMap() {
	gameMap ret;
	playerPath = "user\\" + currentPlayerName + "\\.memoryfile";
	fin.open(playerPath.c_str(), ios::binary | ios::in);
	if (!fin) { ERRORMSG(2); exit(0); }
	fin >> s;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			fin >> ret.map[i][j];
		}
	}
	fin >> ret.gameScore;
	fin >> ret.step;
	fin >> ret.topScore;
	fin.close();
	return ret;
}

string oneUser::getPlayerName() { return currentPlayerName; }

int oneUser::getPlayerID() { return currentPlayerID; }

void oneUser::signin(int id, string name) {
	playerPath = "user\\" + name + "\\.memoryfile";

	fout.open(playerPath.c_str(), ios::binary | ios::out);
	fout << time(NULL) << endl << endl;
	fout << "0 0 0 0" << endl;
	fout << "0 0 0 0" << endl;
	fout << "0 0 0 0" << endl;
	fout << "0 0 0 0" << endl;
	fout << 0 << endl << 0 << endl << endl;
	fout << 0 << endl;

	fout.close();
}

void oneUser::setPlayer(int id, string name) {
	currentPlayerID = id;
	currentPlayerName = name;

	playerPath = "user\\" + currentPlayerName + "\\.memoryfile";
	
}

void oneUser::write(gameMap staffs){
	playerPath = "user\\" + currentPlayerName + "\\.memoryfile";
	fout.open(playerPath.c_str(), ios::binary | ios::out);

	fout << time(NULL) << endl << endl;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			fout << staffs.map[i][j] << ' ';
		}
		fout << endl;
	}
	fout << staffs.gameScore << endl;
	fout << staffs.step << endl << endl;

	fout << staffs.topScore << endl;
}
