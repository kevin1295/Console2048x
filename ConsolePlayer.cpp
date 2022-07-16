#include "ConsolePlayer.h"
#include "BasicFunction.h"
#include <iostream>
#include <conio.h>

ClassOfMessageBox m;

/*
* 
* Below are for the pages
* 
*/

void ConsolePlayer::loadPage() {
    system("cls");
    printf("%s", welcomeWords.c_str());
    printf("%s", loadWords.c_str());

}

string ConsolePlayer::loginPage() {
    printf("%s", getUserNameWords.c_str());
    getline(cin, name);
    conTitle = "title Hello " + name + "! Welcome to 2048 Game!";
    system(conTitle.c_str());
    system("cls");
    return name;
}

void ConsolePlayer::welcomePage() {
    printf("%s", welcomeWords.c_str());
    printf("%s", loadWords.c_str());

    system("cls");
    system(conTitle.c_str());
}

int ConsolePlayer::indexPage() {                                               // show index
    int tempInt;
    system("cls");
    printf("%s", indexTitleWords.c_str());
    printf("%s", indexMenuWords.c_str());
    while (true) {
        tempInt = keyPress();
        switch (tempInt) {
        case 49:
        case 50:
        case 51:
        case 52:
        case 53:
        case 54:
            return tempInt - 48; break;
        case 27:
            return 27;
        }
    }

}

void ConsolePlayer::setEN_US() {
    languageMod = 0;
    welcomeWords = "Welcome to 2048!\n", loadWords = "Loading please wait...",
        indexTitleWords = "--------  Index  --------\n", indexMenuWords = " 1.play \n 2.set ���� \n 3.user \n 4.help \n 5.VisualCommends(Developing) \n 6.Go to github \n # Press ESC to exit \n",
        wrongInputWords = "WrongInput", conTitle = "title welcome to 2048!",
        setTitleWords = "-------- Set --------\n", setMenuWords = " 1.user \n 2.help \n 3.language ���� \n 4.history \n #press ESC to go back\n",
        logInTitle = "-------- Log In --------\n", getUserNameWords = "Please input your nickname: \n",
        infoTitle = "-------- Help --------\n", infoWords = " Welcome to 2048 designed by Jiaye Xu! \n you can press up/down/left/right arrow or W/S/A/D to make blocks drop.\n You can press Esc to interrupt the game, and continue next time.\n The game, at present, does not have GUI, I am looking forward to your help on github! \n #Press any key to go back",
        languageTitle = "-------- Language --------\n", languageWords = " We have the language below for you to choose: \n 0.English \n 1.���ģ����壩 \n";
}

void ConsolePlayer::setZH_CN() {
    languageMod = 1;
    welcomeWords = "��ӭ����2048��\n", loadWords = "���ڼ��������Ժ󡭡�",
        indexTitleWords = "--------  ��ҳ  --------\n", indexMenuWords = " 1.������Ϸ \n 2.���� set \n 3.�û� \n 4.���� \n 5.����ָ����ڿ����� \n 6.��Github�� \n # ���� ESC �˳���Ϸ \n",
        wrongInputWords = "�������", conTitle = "title ��ӭ���� 2048��",
        setTitleWords = "-------- ���� --------\n", setMenuWords = " 1.�û� \n 2.���� \n 3.���� language \n 4.��¼ \n #���� ESC �˳� \n",
        logInTitle = "-------- ��¼ --------\n", getUserNameWords = "�������������� \n",
        infoTitle = "-------- ���� --------\n", infoWords = " ��ӭ����2048�� \n ����԰��� �������ҷ���� �� W/S/A/D ���������ֵ��ƶ���\n ����԰�Esc����ͣ��Ϸ������浵��\n Ŀǰ��Ϸ��û��֧�� GUI �������������������ң����� Github�� \n #�������������",
        languageTitle = "-------- ���� --------\n", languageWords = " ��������ѡ���������� \n 0.English \n 1.���ģ����壩 \n";

}

int ConsolePlayer::settingPage() {                                             // show set
    int tempInt;
    system("cls");
    printf("%s", setTitleWords.c_str());
    printf("%s", setMenuWords.c_str());
    while (true) {
        tempInt = keyPress();
        switch (tempInt) {
        case 49:
            setUserPage(name);
            system("cls");
            printf("%s", setTitleWords.c_str());
            printf("%s", setMenuWords.c_str());
            break;
        case 50:
            setHelpPage();
            system("cls");
            printf("%s", setTitleWords.c_str());
            printf("%s", setMenuWords.c_str());
            break;
        case 51:
            setLanguage();
            system("cls");
            printf("%s", setTitleWords.c_str());
            printf("%s", setMenuWords.c_str());
            break;
        case 52:
            historyPage();
            system("cls");
            printf("%s", setTitleWords.c_str());
            printf("%s", setMenuWords.c_str());
            break;
        case 27:
            return 0;
        }
    }
}

string ConsolePlayer::setUserPage(string orin) {
    if (m.logout()) {
        system("cls");
        printf("%s", logInTitle.c_str());
        return loginPage();
    }
    return orin;
}
void ConsolePlayer::setHelpPage() {
    system("cls");
    printf("%s", infoTitle.c_str());
    printf("%s", infoWords.c_str());
    while (true) {
        if (_kbhit()) {
            system("cls");
            break;
        }
    }
}
void ConsolePlayer::setLanguage() {
    int tempInt;
    system("cls");
    printf("%s", languageTitle.c_str());
    printf("%s", languageWords.c_str());
    tempInt = keyPress();
    switch (tempInt) {
    case 48:
        setEN_US();
        break;
    case 49:
        setZH_CN();
        break;
    }
}

void ConsolePlayer::gameOver(int score, int highestScore) {
    printf("\n\n Game is over. And your score is %d.\n", score);
    while (true) {
        if (_kbhit()) {
            break;
        }
    }
}

void ConsolePlayer::historyPage() {
    NEEDSDEVELOP();
}

/*
* 
* Below are for the game
* 
*/

void ConsolePlayer::blockMap(gameMap map) {
    system("cls");
    printf("--- Top Score: %d --- Step: %d ---\n", map.topScore, map.step);
    printf("----------- score: %d -------------\n", map.gameScore);
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (map.map[i][j]) {
                printf("[ %-8d ]", map.map[i][j]);
            }
            else {
                printf("[          ]");
            }
        }
        printf("\n");
    }
    printf("\n");
}