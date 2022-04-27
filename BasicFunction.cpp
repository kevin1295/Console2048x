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