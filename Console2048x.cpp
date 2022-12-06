// Console2048x.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "GameBox.h"
#include "BasicFunction.h"
#include "ConsolePlayer.h"
#include "MemoryFunction.h"

using namespace std;

GameBox player;
ConsolePlayer Display;
ClassOfMessageBox MsgBox;

gameMap memoryStorage;

bool memoryAvailable;
AllUser all;
oneUser playerHis;

int play() {
    PBI rec;
    Display.loadPage();
    memoryStorage = playerHis.readMap();
    player.initialize(memoryStorage.topScore);
    system("cls");

    if (memoryStorage.step != 0) {
        if (MsgBox.continueGame()) player.setBlocks(memoryStorage);
    }

    while (player.checkStatement()) {
        Display.blockMap(player.getMap());
        switch (keyPress()) {
        case 296:
        case 119:
            rec = player.up();
            if (rec._bool) {
                player.bonus(rec._int);
                player.addBlock();
                break;
            }
            else {
                MsgBox.inputError(); break;
            }
        case 299:
        case 97:
            rec = player.left();
            if (rec._bool) {
                player.bonus(rec._int);
                player.addBlock();
                break;
            }
            else {
                MsgBox.inputError(); break;
            }
        case 304:
        case 115:
            rec = player.down();
            if (rec._bool) {
                player.bonus(rec._int);
                player.addBlock();
                break;
            }
            else {
                MsgBox.inputError(); break;
            }
        case 301:
        case 100:
            rec = player.right();
            if (rec._bool) {
                player.bonus(rec._int);
                player.addBlock();
                break;
            }
            else {
                MsgBox.inputError(); break;
            }
        case 27:
            if (MsgBox.interruptGame()) {
                if (MsgBox.saveProcess()) {
                    playerHis.write(player.getMap());
                    Display.blockMap(player.getMap());
                    return player.getScore();
                }
                else {
                    Display.blockMap(player.getMap());
                    return player.getScore();
                }
            }
            break;

        default:
            MsgBox.inputError();
        }
    }
    Display.blockMap(player.getMap());
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            memoryStorage.map[i][j] = 0;
        }
    }
    memoryStorage.gameScore = 0;
    memoryStorage.step = 0;
    memoryStorage.topScore = max(memoryStorage.topScore, player.getScore());
    playerHis.write(memoryStorage);
    return player.getScore();
}

int main()
{
    int indexReturn, setReturn;
    int mark;
    memoryAvailable = all.initialize();
    switch (all.getLanguage())
    {
    case 0:
        Display.setEN_US();
        break;
    case 1:
        Display.setZH_CN();
        break;
    default:
        Display.setEN_US();
        break;
    }
    
    Display.loadPage();
    system("cls");
    player.setUserName(Display.loginPage());
    while (all.check(player.getUserName()) == -1) {
        if (all.getUserAmount() == 16) {
            MsgBox.memoryFull();
            player.setUserName(Display.loginPage());
        }
        else {
            if (MsgBox.signin()) {
                all.signin(player.getUserName());
                playerHis.signin(all.getUserAmount(), all.getUserName(all.getUserAmount()));
                playerHis.setPlayer(all.getUserAmount(), all.getUserName(all.getUserAmount()));
            }
        }
    }
    Display.loadPage();
    playerHis.setPlayer(all.check(player.getUserName()), player.getUserName());
    memoryStorage = playerHis.readMap();
    system("cls");

    Display.welcomePage();
    while (true) {
        indexReturn = Display.indexPage();
        switch (indexReturn) {
        case 1:
            mark = play();
            Display.gameOver(mark, player.getTopScore());
            break;
        case 2:
            setReturn = Display.settingPage();
            break;
        case 3:
            player.setUserName(Display.setUserPage(player.getUserName()));
            break;
        case 4:
            Display.setHelpPage();
            break;
        case 5:
            NEEDSDEVELOP();
            break;
        case 6:
            system("start https://github.com/kevin1295");
            break;
        case 27:
            return 0;
        }
        all.setLanguage(Display.getLanguage());
    }

    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
