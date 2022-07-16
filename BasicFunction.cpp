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
        MessageBox(NULL, TEXT("��Ǹ�������µİ�ťû�в������壡"), TEXT("�������������"), MB_OK);
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
        return (MessageBox(NULL, TEXT("��ȷ��Ҫ�˳�����˺���"), TEXT("ȷ��"), MB_YESNO) == IDYES);
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
        return (MessageBox(NULL, TEXT("��ȷ��Ҫ�ж���Ϸ��\n������������ѡ�񱣴��������ȣ�"), TEXT("ȷ��"), MB_YESNO) == IDYES);
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
        return (MessageBox(NULL, TEXT("����Ҫ������Ϸ������"), TEXT("ȷ��"), MB_YESNO) == IDYES);
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
        MessageBox(NULL, TEXT("�Բ��𣡵�ǰ�汾�ݲ�֧�ֳ���16���û���\n����Խ������򿽱����µ��ļ���������һ���µĴ浵��"), TEXT("����"), MB_OK);
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
        return (MessageBox(NULL, TEXT("����Ҫ������һ�ε���Ϸ��"), TEXT("ѡ��"), MB_YESNO) == IDYES);
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
        return (MessageBox(NULL, TEXT("����ǳƻ�û������һ�ݴ浵�е�¼������ȷ��Ҫע����"), TEXT("ȷ��"), MB_YESNO) == IDYES);
        break;
    default:
        return (MessageBox(NULL, TEXT("This nickname has not log in on this archieve yet, are you going to sign in?"), TEXT("confirm?"), MB_YESNO) == IDYES);
        break;
    }
}