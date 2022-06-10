# GamwBox.h
```cpp
struct block_box {
	short _int = 0;
	bool _bool = false;
};
struct PBI {
	bool _bool = false;
	int _int = 0;
};

class GameBox {
public:
	block_box blocks[5][5];
	short history[65536][5][5] = {0};
	int pStep = 0;
	void initialize();
	void bonus(int addScore);

	PBI up();
	PBI down();
	PBI left();
	PBI right();

	bool checkStatement();

	void addBlock();

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
```

# BasicFunction.h
```cpp
int keyPress();
void NEEDSDEVELOP();

struct gameMap {
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
```

# ConsolePlayer.h
```cpp
class ConsolePlayer {
public:
	void blockMap(gameMap map);
	
	int indexPage();

	string loginPage();

	void loadPage();

	void welcomePage();

	int settingPage();

	string setUserPage(string orin);

	void setHelpPage();

	void setLanguage();

	void setEN_US();

	void setZH_CN();

	void historyPage();

	void gameOver(int score, int highestScore);

private:

	string name;
	int languageMod = 0;
	string welcomeWords = "Welcome to 2048!\n", loadWords = "Loading please wait...",
		indexTitleWords = "--------  Index  --------\n", indexMenuWords = " 1.play \n 2.set 设置 \n 3.user \n 4.help \n 5.VisualCommends(Developing) \n 6.Go to github \n # Press ESC to exit \n",
		wrongInputWords = "WrongInput", conTitle = "title welcome to 2048!",
		setTitleWords = "-------- Set --------\n", setMenuWords = " 1.user \n 2.help \n 3.language 语言 \n 4.history \n #press ESC to go back\n",
		logInTitle = "-------- Log In --------\n", getUserNameWords = "Please input your nickname: \n",
		infoTitle = "-------- Help --------\n", infoWords = " Welcome to 2048 designed by Jiaye Xu! \n you can press up/down/left/right arrow or W/S/A/D to make blocks drop.\n The game, at present, does not have GUI, I am looking forward to your help on github! \n #Press any key to go back",
		languageTitle = "-------- Language --------\n", languageWords = " We have the language below for you to choose: \n 0.English \n 1.中文（简体） \n";
};
```