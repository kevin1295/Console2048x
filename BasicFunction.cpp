#include "BasicFunction.h"
#include <conio.h>
#include <windows.h>

int keyPress() {                                            // Turn key board hit into ASCIIcode
    int keyBoardRecord;
    while (true) {
        if (_kbhit()) {
            keyBoardRecord = _getch();
            if (keyBoardRecord != 224) {
                return keyBoardRecord;
                break;
            }
            else {
                while (true) {
                    if (_kbhit()) {
                        keyBoardRecord = _getch();
                        return 224 + keyBoardRecord;
                        break;
                    }
                }
            }
        }
    }
}

void NEEDSDEVELOP() {
    MessageBox(NULL, TEXT("Sorry,this part still needs developing!"), TEXT("caution"), MB_OK);
}

int ERRORMSG(int errorCode) {
    switch (errorCode) {
    case 1:
        if (MessageBox(NULL, TEXT("The archive read or write failure! Error Code: 01 \nDo you want to continue playing with out archive?"), TEXT("ERROR"), MB_YESNO) == IDYES) {
            return 1;
        }
        exit(0);
        break;
    case 2:
        MessageBox(NULL, TEXT("Sorry! We met a problem! \nThe archive read or write failure! Error Code: 02 \nIf you have free time, please report this to the developers! \nVia https://github.com/kevin1295 or 1974394215@qq.com"), TEXT("ERROR"), MB_OK);
        exit(0);
        break;


    default:
        return -1;
    }
    return 0;
}

void ClassOfMessageBox::inputError() {
    switch (languageMod) {
    case 0:
        MessageBox(NULL, TEXT("You pressed the wrong key!"), TEXT("WrongInput"), MB_OK);
        break;
    case 1:
        MessageBox(NULL, TEXT("抱歉，您按下的按钮没有操作意义！"), TEXT("错误的输入内容"), MB_OK);
        break;
    default:
        MessageBox(NULL, TEXT("You pressed the wrong key!"), TEXT("WrongInput"), MB_OK);
        break;
    }
}
bool ClassOfMessageBox::logout() {
    switch (languageMod) {
    case 0:
        return (MessageBox(NULL, TEXT("Do you really want to log out?"), TEXT("Confirm?"), MB_YESNO) == IDYES);
        break;
    case 1:
        return (MessageBox(NULL, TEXT("你确定要退出这个账号吗？"), TEXT("确认"), MB_YESNO) == IDYES);
        break;
    default:
        return (MessageBox(NULL, TEXT("Do you really want to log out?"), TEXT("Confirm?"), MB_YESNO) == IDYES);
        break;
    }
}
bool ClassOfMessageBox::interruptGame() {
    switch (languageMod) {
    case 0:
        return (MessageBox(NULL, TEXT("Are you sure to interrupt the game?\n(You can choose to save the process later)"), TEXT("Confirm?"), MB_YESNO) == IDYES);
        break;
    case 1:
        return (MessageBox(NULL, TEXT("你确定要中断游戏吗？\n（接下来可以选择保存或放弃进度）"), TEXT("确认"), MB_YESNO) == IDYES);
        break;
    default:
        return (MessageBox(NULL, TEXT("Are you sure to interrupt the game?\n(You can choose to save the process later)"), TEXT("Confirm?"), MB_YESNO) == IDYES);
        break;
    }
}
bool ClassOfMessageBox::saveProcess() {
    switch (languageMod) {
    case 0:
        return (MessageBox(NULL, TEXT("Do you want to save the process?"), TEXT("confirm?"), MB_YESNO) == IDYES);
        break;
    case 1:
        return (MessageBox(NULL, TEXT("你想要保存游戏进度吗？"), TEXT("确认"), MB_YESNO) == IDYES);
        break;
    defualt:
        return (MessageBox(NULL, TEXT("Do you want to save the process?"), TEXT("confirm?"), MB_YESNO) == IDYES);
        break;
    }
}
void ClassOfMessageBox::memoryFull() {
    switch (languageMod) {
    case 0:
        MessageBox(NULL, TEXT("Sorry! The current version can't support more than 16 players! \nYou can copy the main program to another folder environment and start a new archive."), TEXT("Limit"), MB_OK);
        break;
    case 1:
        MessageBox(NULL, TEXT("对不起！当前版本暂不支持超过16个用户！\n你可以将主程序拷贝至新的文件夹来启动一份新的存档。"), TEXT("限制"), MB_OK);
        break;
    default:
        MessageBox(NULL, TEXT("Sorry! The current version can't support more than 16 players! \nYou can copy the main program to another folder environment and start a new archive."), TEXT("Limit"), MB_OK);
        break;
    }
}
bool ClassOfMessageBox::continueGame()
{
    switch (languageMod) {
    case 0:
        return (MessageBox(NULL, TEXT("Do you want to continue the game you played last time?"), TEXT("Option"), MB_YESNO) == IDYES);
        break;
    case 1:
        return (MessageBox(NULL, TEXT("您想要继续上一次的游戏吗？"), TEXT("选项"), MB_YESNO) == IDYES);
        break;
    default:
        return (MessageBox(NULL, TEXT("Do you want to continue the game you played last time?"), TEXT("Option"), MB_YESNO) == IDYES);
        break;
    }
}
bool ClassOfMessageBox::signin() {
    switch (languageMod) {
    case 0:
        return (MessageBox(NULL, TEXT("This nickname has not log in on this archieve yet, are you going to sign in?"), TEXT("confirm?"), MB_YESNO) == IDYES);
        break;
    case 1:
        return (MessageBox(NULL, TEXT("这个昵称还没有在这一份存档中登录过，你确定要注册吗？"), TEXT("确认"), MB_YESNO) == IDYES);
        break;
    default:
        return (MessageBox(NULL, TEXT("This nickname has not log in on this archieve yet, are you going to sign in?"), TEXT("confirm?"), MB_YESNO) == IDYES);
        break;
    }
}