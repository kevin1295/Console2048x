#include "GameBox.h"
#include "BasicFunction.h"
#include <random>
#include <time.h>

/*
* 
* Below are the functions for the general game
* 
*/ 

using namespace std;

int GameBox::getScore() { return score; }

std::string GameBox::getUserName() { return userName; }

void GameBox::setUserName(string name) { userName = name; }


int GameBox::getTopScore() { return historyTopScore; }


gameMap GameBox::getMap() {
    gameMap ret;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            ret.map[i][j] = blocks[i][j]._int;
        }
    }
    ret.gameScore = score;
    ret.step = pStep;
    ret.topScore = historyTopScore;
    return ret;
}

void GameBox::initialize(int historyTop) {
    score = 0;
    historyTopScore = historyTop;
    memset(blocks, 0, sizeof(blocks));
    srand(int(time(0)));
    blocks[rand() % 4 + 1][rand() % 4 + 1]._int = (rand() % 2 + 1) * 2;
    blocks[rand() % 4 + 1][rand() % 4 + 1]._int = (rand() % 2 + 1) * 2;
}

void GameBox::setBlocks(gameMap sourse){
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            blocks[i][j]._int = sourse.map[i][j];
            blocks[i][j]._bool = false;
        }
    }
    pStep = sourse.step;
    historyTopScore = sourse.topScore;
    score = sourse.gameScore;
}

void GameBox::bonus(int addScore) {
    score += addScore;
}

bool GameBox::checkStatement() {                                // Check whether the game is over
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j < 4; j++) {
            if ((!blocks[i][j]._int) || (blocks[i][j]._int == blocks[i + 1][j]._int) || (blocks[i][j]._int == blocks[i][j + 1]._int)) {
                return true;
            }
        }
    }
    for (int i = 1; i < 4; i++) {
        if (!(blocks[4][i]._int) || (blocks[4][i]._int == blocks[4][i + 1]._int) || (!blocks[i][4]._int) || (blocks[i][4]._int == blocks[i + 1][4]._int)) {
            return true;
        }
    }
    if (!blocks[4][4]._int) {
        return true;
    }
    return false;
}

/*
* 
* Below are for the functions for the blocks
* 
*/

PBI GameBox::up() {
    PBI ret;
    ret._bool = false;
    ret._int = 0;
    copy();
    for (int i = 2; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {

            if (blocksCopy[i][j]._int) {
                iCopy = i, jCopy = j;
                while (!blocksCopy[iCopy - 1][jCopy]._int) {
                    blocksCopy[iCopy - 1][jCopy]._int = blocksCopy[iCopy][jCopy]._int;
                    blocksCopy[iCopy - 1][jCopy]._bool = blocksCopy[iCopy][jCopy]._bool;
                    blocksCopy[iCopy][jCopy]._int = 0;
                    ret._bool = true;
                    if (iCopy != 2) {
                        iCopy--;
                    }
                    else {
                        break;
                    }
                }
                if (blocksCopy[iCopy - 1][jCopy]._int == blocksCopy[iCopy][jCopy]._int && blocksCopy[iCopy - 1][jCopy]._bool == false && blocksCopy[iCopy][jCopy]._bool == false) {
                    blocksCopy[iCopy][jCopy]._int = 0;
                    blocksCopy[iCopy - 1][jCopy]._int *= 2;
                    ret._int += blocksCopy[iCopy - 1][jCopy]._int;
                    blocksCopy[iCopy - 1][jCopy]._bool = true;
                    ret._bool = true;
                }
            }

        }
    }
    if (ret._bool) {
        memcpy(blocks, blocksCopy, sizeof(blocksCopy));
        ++pStep;
        historyTopScore = max(historyTopScore, score + ret._int);
        return ret;
    }
    ret._int = 0;
    return ret;
}

PBI GameBox::left() {
    PBI ret;
    ret._bool = false;
    ret._int = 0;
    copy();
    for (int i = 1; i <= 4; i++) {
        for (int j = 2; j <= 4; j++) {

            if (blocksCopy[i][j]._int) {
                iCopy = i, jCopy = j;
                while (!blocksCopy[iCopy][jCopy - 1]._int) {
                    blocksCopy[iCopy][jCopy - 1]._int = blocksCopy[iCopy][jCopy]._int;
                    blocksCopy[iCopy][jCopy - 1]._bool = blocksCopy[iCopy][jCopy]._bool;
                    blocksCopy[iCopy][jCopy]._int = 0;
                    ret._bool = true;
                    if (jCopy != 2) {
                        jCopy--;
                    }
                    else {
                        break;
                    }
                }
                if (blocksCopy[iCopy][jCopy - 1]._int == blocksCopy[iCopy][jCopy]._int && blocksCopy[iCopy][jCopy - 1]._bool == false && blocksCopy[iCopy][jCopy]._bool == false) {
                    blocksCopy[iCopy][jCopy]._int = 0;
                    blocksCopy[iCopy][jCopy - 1]._int *= 2;
                    ret._int += blocksCopy[iCopy][jCopy - 1]._int;
                    blocksCopy[iCopy][jCopy - 1]._bool = true;
                    ret._bool = true;
                }
            }

        }
    }
    if (ret._bool) {
        memcpy(blocks, blocksCopy, sizeof(blocksCopy));
        ++pStep;
        historyTopScore = max(historyTopScore, score + ret._int);
        return ret;
    }
    ret._int = 0;
    return ret;
}

PBI GameBox::down() {
    PBI ret;
    ret._bool = false;
    ret._int = 0;
    copy();
    for (int i = 1; i <= 4; i++) {
        for (int j = 3; j >= 1; j--) {

            if (blocksCopy[j][i]._int) {
                iCopy = i; jCopy = j;
                while (!blocksCopy[jCopy + 1][iCopy]._int) {
                    blocksCopy[jCopy + 1][iCopy]._int = blocksCopy[jCopy][iCopy]._int;
                    blocksCopy[jCopy + 1][iCopy]._bool = blocksCopy[jCopy][iCopy]._bool;
                    blocksCopy[jCopy][iCopy]._int = 0;
                    ret._bool = true;
                    if (jCopy != 3) {
                        jCopy++;
                    }
                    else {
                        break;
                    }
                }
                if (blocksCopy[jCopy + 1][iCopy]._int == blocksCopy[jCopy][iCopy]._int && blocksCopy[jCopy + 1][iCopy]._bool == false && blocksCopy[jCopy][iCopy]._bool == false) {
                    blocksCopy[jCopy][iCopy]._int = 0;
                    blocksCopy[jCopy + 1][iCopy]._int *= 2;
                    ret._int += blocksCopy[jCopy + 1][iCopy]._int;
                    blocksCopy[jCopy + 1][iCopy]._bool = true;
                    ret._bool = true;
                }
            }

        }
    }
    if (ret._bool) {
        memcpy(blocks, blocksCopy, sizeof(blocksCopy));
        ++pStep;
        historyTopScore = max(historyTopScore, score + ret._int);
        return ret;
    }
    ret._int = 0;
    return ret;
}

PBI GameBox::right() {
    PBI ret;
    ret._bool = false;
    ret._int = 0;
    copy();
    for (int i = 1; i <= 4; i++) {
        for (int j = 3; j >=1 ; j--) {

            if (blocksCopy[i][j]._int) {
                iCopy = i, jCopy = j;
                while (!blocksCopy[iCopy][jCopy + 1]._int) {
                    blocksCopy[iCopy][jCopy + 1]._int = blocksCopy[iCopy][jCopy]._int;
                    blocksCopy[iCopy][jCopy + 1]._bool = blocksCopy[iCopy][jCopy]._bool;
                    blocksCopy[iCopy][jCopy]._int = 0;
                    ret._bool = true;
                    if (jCopy != 3) {
                        jCopy++;
                    }
                    else {
                        break;
                    }
                }
                if (blocksCopy[iCopy][jCopy + 1]._int == blocksCopy[iCopy][jCopy]._int && blocksCopy[iCopy][jCopy + 1]._bool == false && blocksCopy[iCopy][jCopy]._bool == false) {
                    blocksCopy[iCopy][jCopy]._int = 0;
                    blocksCopy[iCopy][jCopy + 1]._int *= 2;
                    ret._int += blocksCopy[iCopy][jCopy + 1]._int;
                    blocksCopy[iCopy][jCopy + 1]._bool = true;
                    ret._bool = true;
                }
            }

        }
    }
    if (ret._bool) {
        memcpy(blocks, blocksCopy, sizeof(blocksCopy));
        ++pStep;
        historyTopScore = max(historyTopScore, score + ret._int);
        return ret;
    }
    ret._int = 0;
    return ret;
}

void GameBox::copy() {                              // An extra function
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            blocksCopy[i][j]._int = blocks[i][j]._int;
            blocksCopy[i][j]._bool = false;
        }
    }
}

void GameBox::addBlock() {
    int numAppear, yAppear, xAppear;
    numAppear = rand() % 16;                                // This neams to add a block at the No.(rand()) spare block 
    yAppear = 0;
    xAppear = 0;
    while (numAppear > 0) {
        numAppear--;
        xAppear = (xAppear + 1) % 4;
        if (xAppear == 0) {
            yAppear = (yAppear + 1) % 4;
        }
        while (blocks[xAppear + 1][yAppear + 1]._int) {
            xAppear = (xAppear + 1) % 4;
            if (xAppear == 0) {
                yAppear = (yAppear + 1) % 4;
            }
        }
    }
    blocks[xAppear % 4 + 1][yAppear % 4 + 1]._int = (rand() % 2 + 1) * 2;
}
