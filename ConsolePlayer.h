// ConsolePlayer.h
#pragma once

/*
* 
* This head is written for the programs which use Console as GUI in the project
* 
*/

#include <string>
#include "BasicFunction.h"
using namespace std;

class ConsolePlayer {
public:
	void blockMap(gameMap map);
	
	int indexPage();

	string loginPage();

	void loadPage();

	void welcomePage();

	int settingPage();

	void setUserPage();
	// MsgBox and jump to loginPage

	void setHelpPage();

	void setLanguage();

	void setEN_US();

	void setZH_CN();

private:
	int languageMod = 0;
	string welcomeWords = "Welcome to 2048!\n", loadWords = "Loading please wait...",
		indexTitleWords = "--------  Index  --------\n", indexMenuWords = " 1.play \n 2.set 设置 \n 3.user \n 4.help \n 5.VisualCommends(Developing) \n 6.Go to github \n # Press ESC to exit \n",
		wrongInputWords = "WrongInput", conTitle = "title welcome to 2048!",
		setTitleWords = "-------- Set --------\n", setMenuWords = " 1.user \n 2.help \n 3.language 语言 \n 4.history \n #press ESC to go back\n",
		logInTitle = "-------- Log In --------\n", getUserNameWords = "Please input your nickname: \n",
		infoTitle = "-------- Help --------\n", infoWords = " Welcome to 2048 designed by Jiaye Xu! \n you can press up/down/left/right arrow or W/S/A/D to make blocks drop.\n The game, at present, does not have GUI, I am looking forward to your help on github! \n #Press any key to go back",
		languageTitle = "-------- Language --------\n", languageWords = " We have the language below for you to choose: \n 0.English \n 1.中文（简体） \n";
};