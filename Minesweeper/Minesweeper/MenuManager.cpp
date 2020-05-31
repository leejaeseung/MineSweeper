#include "MenuManager.h"
#include "config.h"
#include <iostream>
using namespace std;

MenuManager::MenuManager()
    :started(false), saved(false), mode(1), width(10), height(10)
{
    setCursorView(0);
}

void MenuManager::printMenu()
{
    int x = MENU_TITLE_X, y = MENU_TITLE_Y;
	gotoxy(x, y++);
        cout << " __       __  __                             ______                                                                  ";
        gotoxy(x, y++);
        cout << "/  \\     /  |/  |                           /      \\                                                                 ";
        gotoxy(x, y++);
        cout << "$$  \\   /$$ |$$/  _______    ______        /$$$$$$  | __   __   __   ______    ______    ______    ______    ______  ";
        gotoxy(x, y++);
        cout << "$$$  \\ /$$$ |/  |/       \\  /      \\       $$ \\__$$/ /  | /  | /  | /      \\  /      \\  /      \\  /      \\  /      \\ ";
        gotoxy(x, y++);
        cout << "$$$$  /$$$$ |$$ |$$$$$$$  |/$$$$$$  |      $$      \\ $$ | $$ | $$ |/$$$$$$  |/$$$$$$  |/$$$$$$  |/$$$$$$  |/$$$$$$  |";
        gotoxy(x, y++);
        cout << "$$ $$ $$/$$ |$$ |$$ |  $$ |$$    $$ |       $$$$$$  |$$ | $$ | $$ |$$    $$ |$$    $$ |$$ |  $$ |$$    $$ |$$ |  $$/ ";
        gotoxy(x, y++);
        cout << "$$ |$$$/ $$ |$$ |$$ |  $$ |$$$$$$$$/       /  \\__$$ |$$ \\_$$ \\_$$ |$$$$$$$$/ $$$$$$$$/ $$ |__$$ |$$$$$$$$/ $$ |      ";
        gotoxy(x, y++);
        cout << "$$ | $/  $$ |$$ |$$ |  $$ |$$       |      $$    $$/ $$   $$   $$/ $$       |$$       |$$    $$/ $$       |$$ |      ";
        gotoxy(x, y++);
        cout << "$$/      $$/ $$/ $$/   $$/  $$$$$$$/        $$$$$$/   $$$$$/$$$$/   $$$$$$$/  $$$$$$$/ $$$$$$$/   $$$$$$$/ $$/       ";
        gotoxy(x, y++);
        cout << "                                                                                       $$ |                          ";
        gotoxy(x, y++);
        cout << "                                                                                       $$ |                          ";
        gotoxy(x, y++);
        cout << "                                                                                       $$/                           ";

        x = MENU_LEVEL_X;
        y = MENU_LEVEL_Y;
        gotoxy(x, y++);
        cout << " __        ________  __     __  ________  __       ";
        gotoxy(x, y++);
        cout << "/  |      /        |/  |   /  |/        |/  |      ";
        gotoxy(x, y++);
        cout << "$$ |      $$$$$$$$/ $$ |   $$ |$$$$$$$$/ $$ |      ";
        gotoxy(x, y++);
        cout << "$$ |      $$ |__    $$ |   $$ |$$ |__    $$ |      ";
        gotoxy(x, y++);
        cout << "$$ |      $$    |   $$  \\ /$$/ $$    |   $$ |      ";
        gotoxy(x, y++);
        cout << "$$ |      $$$$$/     $$  /$$/  $$$$$/    $$ |      ";
        gotoxy(x, y++);
        cout << "$$ |_____ $$ |_____   $$ $$/   $$ |_____ $$ |_____ ";
        gotoxy(x, y++);
        cout << "$$       |$$       |   $$$/    $$       |$$       |";
        gotoxy(x, y++);
        cout << "$$$$$$$$/ $$$$$$$$/     $/     $$$$$$$$/ $$$$$$$$/ ";

        printEasy(MENU_CHOOSE_FCOLOR, MENU_CHOOSE_BGCOLOR);
        printNormal(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
        printHard(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);

        x = MENU_MAP_X;
        y = MENU_MAP_Y;
        gotoxy(x, y++);
        cout << " __       __   ______   _______  ";
        gotoxy(x, y++);
        cout << "/  \\     /  | /      \\ /       \\ ";
        gotoxy(x, y++);
        cout << "$$  \\   /$$ |/$$$$$$  |$$$$$$$  |";
        gotoxy(x, y++);
        cout << "$$$  \\ /$$$ |$$ |__$$ |$$ |__$$ |";
        gotoxy(x, y++);
        cout << "$$$$  /$$$$ |$$    $$ |$$    $$/ ";
        gotoxy(x, y++);
        cout << "$$ $$ $$/$$ |$$$$$$$$ |$$$$$$$/  ";
        gotoxy(x, y++);
        cout << "$$ |$$$/ $$ |$$ |  $$ |$$ |      ";
        gotoxy(x, y++);
        cout << "$$ | $/  $$ |$$ |  $$ |$$ |      ";
        gotoxy(x, y++);
        cout << "$$/      $$/ $$/   $$/ $$/       ";

        printWidthMinus1(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
        printWidthMinus10(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
        printWidth();
        printWidthPlus1(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
        printWidthPlus10(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);

        printHeightMinus1(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
        printHeightMinus10(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
        printHeight();
        printHeightPlus1(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
        printHeightPlus10(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);

        printNewGame();
        if (saved)
            printContinueGame(MENU_DEFAULT_FCOLOR);
        else
            printContinueGame(MENU_UNACTIVATE_FCOLOR);
}



void MenuManager::printEasy(const int& color, const int& bgcolor) {
    int x = MENU_EASY_X;
    int y = MENU_EASY_Y;

    gotoxy(x, y++);
    cout << "┌ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┐";
    gotoxy(x, y++);
    cout << "ㅣ";
    setColor(MENU_DEFAULT_FCOLOR, bgcolor);
    cout << "                                             ";
    setColor(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
    cout << "ㅣ";
    gotoxy(x, y++);
    cout << "ㅣ";
    setColor(color, bgcolor);
    cout << "          E  A  S  Y     M  O  D  E          ";
    setColor(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
    cout << "ㅣ";
    gotoxy(x, y++);
    cout << "ㅣ";
    setColor(MENU_DEFAULT_FCOLOR, bgcolor);
    cout << "                                             ";
    setColor(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
    cout << "ㅣ";
    gotoxy(x, y++);
    cout << "├ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┤";
}

void MenuManager::printNormal(const int& color, const int& bgcolor) {
    int x = MENU_NORMAL_X;
    int y = MENU_NORMAL_Y;

    gotoxy(x, y++);
    cout << "├ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┤";
    gotoxy(x, y++);
    cout << "ㅣ";
    setColor(MENU_DEFAULT_FCOLOR, bgcolor);
    cout << "                                             ";
    setColor(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
    cout << "ㅣ";
    gotoxy(x, y++);
    cout << "ㅣ";
    setColor(color, bgcolor);
    cout << "    N  O  R  M  A  L     M  O  D  E          ";
    setColor(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
    cout << "ㅣ";
    gotoxy(x, y++);
    cout << "ㅣ";
    setColor(MENU_DEFAULT_FCOLOR, bgcolor);
    cout << "                                             ";
    setColor(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
    cout << "ㅣ";
    gotoxy(x, y++);
    cout << "├ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┤";
}

void MenuManager::printHard(const int& color, const int& bgcolor) {
    int x = MENU_HARD_X;
    int y = MENU_HARD_Y;

    gotoxy(x, y++);
    cout << "├ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┤";
    gotoxy(x, y++);
    cout << "ㅣ";
    setColor(MENU_DEFAULT_FCOLOR, bgcolor);
    cout << "                                             ";
    setColor(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
    cout << "ㅣ";
    gotoxy(x, y++);
    cout << "ㅣ";
    setColor(color, bgcolor);
    cout << "          H  A  R  D     M  O  D  E          ";
    setColor(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
    cout << "ㅣ";
    gotoxy(x, y++);
    cout << "ㅣ";
    setColor(MENU_DEFAULT_FCOLOR, bgcolor);
    cout << "                                             ";
    setColor(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
    cout << "ㅣ";
    gotoxy(x, y++);
    cout << "└ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ┘";
}

void MenuManager::printWidthPlus1(const int& color, const int& bgcolor)
{
    int x = MENU_WIDTH_PLUS_1_X;
    int y = MENU_WIDTH_PLUS_1_Y;

    gotoxy(x, y++);
    cout << "┬ㅡㅡㅡ┐";
    gotoxy(x, y++);
    cout << "ㅣ";
    setColor(color, bgcolor);
    cout << " + 1 ";
    setColor(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
    cout << "ㅣ";
    gotoxy(x, y++);
    cout << "┼ㅡㅡㅡ┤";
}

void MenuManager::printWidthPlus10(const int& color, const int& bgcolor)
{
    int x = MENU_WIDTH_PLUS_10_X;
    int y = MENU_WIDTH_PLUS_10_Y;

    gotoxy(x, y++);
    cout << "┼ㅡㅡㅡ┤";
    gotoxy(x, y++);
    cout << "ㅣ";
    setColor(color, bgcolor);
    cout << " + 10";
    setColor(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
    cout << "ㅣ";
    gotoxy(x, y++);
    cout << "┴ㅡㅡㅡ┘";
}

void MenuManager::printWidthMinus1(const int& color, const int& bgcolor)
{
    int x = MENU_WIDTH_MINUS_1_X;
    int y = MENU_WIDTH_MINUS_1_Y;

    gotoxy(x, y++);
    cout << "┌ㅡㅡㅡ┬";
    gotoxy(x, y++);
    cout << "ㅣ";
    setColor(color, bgcolor);
    cout << " - 1 ";
    setColor(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
    cout << "ㅣ";
    gotoxy(x, y++);
    cout << "├ㅡㅡㅡ┼";
}

void MenuManager::printWidthMinus10(const int& color, const int& bgcolor)
{
    int x = MENU_WIDTH_MINUS_10_X;
    int y = MENU_WIDTH_MINUS_10_Y;

    gotoxy(x, y++);
    cout << "├ㅡㅡㅡ┼";
    gotoxy(x, y++);
    cout << "ㅣ";
    setColor(color, bgcolor);
    cout << " - 10";
    setColor(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
    cout << "ㅣ";
    gotoxy(x, y++);
    cout << "└ㅡㅡㅡ┴";
}

void MenuManager::printWidth()
{
    int x = MENU_WIDTHBOX_X;
    int y = MENU_WIDTHBOX_Y;

    gotoxy(x, y++);
    cout << "┬ㅡㅡㅡㅡㅡ┬";
    gotoxy(x, y++);
    cout << "ㅣW I D T Hㅣ";
    gotoxy(x, y++);
    cout << "┼ㅡㅡㅡㅡㅡ┼";
    gotoxy(x, y++);
    cout << "ㅣ         ㅣ";
    gotoxy(x, y++);
    cout << "┴ㅡㅡㅡㅡㅡ┴";
    
    gotoxy(MENU_WIDTH_OUT_X, MENU_WIDTH_OUT_Y);
    cout << width;
}

void MenuManager::printHeightPlus1(const int& color, const int& bgcolor)
{
    int x = MENU_HEIGHT_PLUS_1_X;
    int y = MENU_HEIGHT_PLUS_1_Y;

    gotoxy(x, y++);
    cout << "┬ㅡㅡㅡ┐";
    gotoxy(x, y++);
    cout << "ㅣ";
    setColor(color, bgcolor);
    cout << " + 1 ";
    setColor(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
    cout << "ㅣ";
    gotoxy(x, y++);
    cout << "┼ㅡㅡㅡ┤";
}

void MenuManager::printHeightPlus10(const int& color, const int& bgcolor)
{
    int x = MENU_HEIGHT_PLUS_10_X;
    int y = MENU_HEIGHT_PLUS_10_Y;

    gotoxy(x, y++);
    cout << "┼ㅡㅡㅡ┤";
    gotoxy(x, y++);
    cout << "ㅣ";
    setColor(color, bgcolor);
    cout << " + 10";
    setColor(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
    cout << "ㅣ";
    gotoxy(x, y++);
    cout << "┴ㅡㅡㅡ┘";
}

void MenuManager::printHeightMinus1(const int& color, const int& bgcolor)
{
    int x = MENU_HEIGHT_MINUS_1_X;
    int y = MENU_HEIGHT_MINUS_1_Y;

    gotoxy(x, y++);
    cout << "┌ㅡㅡㅡ┬";
    gotoxy(x, y++);
    cout << "ㅣ";
    setColor(color, bgcolor);
    cout << " - 1 ";
    setColor(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
    cout << "ㅣ";
    gotoxy(x, y++);
    cout << "├ㅡㅡㅡ┼";
}

void MenuManager::printHeightMinus10(const int& color, const int& bgcolor)
{
    int x = MENU_HEIGHT_MINUS_10_X;
    int y = MENU_HEIGHT_MINUS_10_Y;

    gotoxy(x, y++);
    cout << "├ㅡㅡㅡ┼";
    gotoxy(x, y++);
    cout << "ㅣ";
    setColor(color, bgcolor);
    cout << " - 10";
    setColor(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
    cout << "ㅣ";
    gotoxy(x, y++);
    cout << "└ㅡㅡㅡ┴";
}

void MenuManager::printHeight()
{
    int x = MENU_HEIGHTBOX_X;
    int y = MENU_HEIGHTBOX_Y;

    gotoxy(x, y++);
    cout << "┬ㅡㅡㅡㅡㅡㅡ┬";
    gotoxy(x, y++);
    cout << "ㅣH E I G H Tㅣ";
    gotoxy(x, y++);
    cout << "┼ㅡㅡㅡㅡㅡㅡ┼";
    gotoxy(x, y++);
    cout << "ㅣ           ㅣ";
    gotoxy(x, y++);
    cout << "┴ㅡㅡㅡㅡㅡㅡ┴";

    gotoxy(MENU_HEIGHT_OUT_X, MENU_HEIGHT_OUT_Y);
    cout << height;
}

void MenuManager::changeMode(const int& prevMode, const int& nextMode) {
    switch (prevMode) {
    case 1:
        printEasy(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
        break;
    case 2:
        printNormal(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
        break;
    case 3:
        printHard(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
        break;
    default:
        break;
    }
    switch (nextMode) {
    case 1:
        printEasy(MENU_CHOOSE_FCOLOR, MENU_CHOOSE_BGCOLOR);
        break;
    case 2:
        printNormal(MENU_CHOOSE_FCOLOR, MENU_CHOOSE_BGCOLOR);
        break;
    case 3:
        printHard(MENU_CHOOSE_FCOLOR, MENU_CHOOSE_BGCOLOR);
        break;
    default:
        break;
    }

    mode = nextMode;
}

void MenuManager::changeWidth(const int& select, const int& nextWidth)
{
    switch (select) {
    case 1:
        printWidthMinus1(MENU_CHOOSE_FCOLOR, MENU_CHOOSE_BGCOLOR);
        Sleep(CLICK_DELAY);
        printWidthMinus1(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
        break;
    case 2:
        printWidthMinus10(MENU_CHOOSE_FCOLOR, MENU_CHOOSE_BGCOLOR);
        Sleep(CLICK_DELAY);
        printWidthMinus10(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
        break;
    case 3:
        printWidthPlus1(MENU_CHOOSE_FCOLOR, MENU_CHOOSE_BGCOLOR);
        Sleep(CLICK_DELAY);
        printWidthPlus1(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
        break;
    case 4:
        printWidthPlus10(MENU_CHOOSE_FCOLOR, MENU_CHOOSE_BGCOLOR);
        Sleep(CLICK_DELAY);
        printWidthPlus10(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
        break;
    default:
        break;
    }
    
    printWidth();
}

void MenuManager::changeHeight(const int& select, const int& nextHeight)
{
    switch (select) {
    case 1:
        printHeightMinus1(MENU_CHOOSE_FCOLOR, MENU_CHOOSE_BGCOLOR);
        Sleep(CLICK_DELAY);
        printHeightMinus1(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
        break;
    case 2:
        printHeightMinus10(MENU_CHOOSE_FCOLOR, MENU_CHOOSE_BGCOLOR);
        Sleep(CLICK_DELAY);
        printHeightMinus10(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
        break;
    case 3:
        printHeightPlus1(MENU_CHOOSE_FCOLOR, MENU_CHOOSE_BGCOLOR);
        Sleep(CLICK_DELAY);
        printHeightPlus1(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
        break;
    case 4:
        printHeightPlus10(MENU_CHOOSE_FCOLOR, MENU_CHOOSE_BGCOLOR);
        Sleep(CLICK_DELAY);
        printHeightPlus10(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
        break;
    default:
        break;
    }

    printHeight();
}

void MenuManager::printNewGame()
{
    int x = MENU_NEW_GAME_X;
    int y = MENU_NEW_GAME_Y;

    gotoxy(x, y++);
    cout << "┌ㅡㅡㅡㅡㅡㅡㅡㅡㅡ┐";
    gotoxy(x, y++);
    cout << "ㅣ                 ㅣ";
    gotoxy(x, y++);
    cout << "ㅣ     N  E  W     ㅣ";
    gotoxy(x, y++);
    cout << "ㅣ                 ㅣ";
    gotoxy(x, y++);
    cout << "└ㅡㅡㅡㅡㅡㅡㅡㅡㅡ┘";
}

void MenuManager::printContinueGame(const int& color)
{
    int x = MENU_CONTINUE_GAME_X;
    int y = MENU_CONTINUE_GAME_Y;

    gotoxy(x, y++);
    cout << "┌ㅡㅡㅡㅡㅡㅡㅡㅡㅡ┐";
    gotoxy(x, y++);
    cout << "ㅣ                 ㅣ";
    gotoxy(x, y++);
    cout << "ㅣ";
    setColor(color, MENU_DEFAULT_BGCOLOR);
    cout << " C O N T I N U E ";
    setColor(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
    cout << "ㅣ";
    gotoxy(x, y++);
    cout << "ㅣ                 ㅣ";
    gotoxy(x, y++);
    cout << "└ㅡㅡㅡㅡㅡㅡㅡㅡㅡ┘";
}

int MenuManager::process(const int& x, const int& y)
//리턴값이 0 = 메뉴 유지, 1 = 처음부터 , 2 = 이어하기
{
    if (x > MENU_EASY_X + 1 && x <= MENU_HARD_X + MENU_LEVEL_COL && y > MENU_EASY_Y&& y <= MENU_HARD_Y + MENU_LEVEL_ROW) {
        //난이도를 선택했을 때
        int nextMode = 0;
        if (x > MENU_EASY_X&& x <= MENU_EASY_X + MENU_LEVEL_COL && y > MENU_EASY_Y&& y <= MENU_EASY_Y + MENU_LEVEL_ROW) {
            //Easy 모드 선택 시
            nextMode = 1;
        }
        else if (x > MENU_NORMAL_X&& x <= MENU_NORMAL_X + MENU_LEVEL_COL && y > MENU_NORMAL_Y&& y <= MENU_NORMAL_Y + MENU_LEVEL_ROW) {
            //Normal 모드 선택 시
            nextMode = 2;
        }
        else if (x > MENU_HARD_X&& x <= MENU_HARD_X + MENU_LEVEL_COL && y > MENU_HARD_Y&& y <= MENU_HARD_Y + MENU_LEVEL_ROW) {
            //Hard 모드 선택 시
            nextMode = 3;
        }
        else return 0;
        changeMode(mode, nextMode);
    }
    else if (x > MENU_WIDTH_MINUS_1_X + 1 && x <= MENU_WIDTH_PLUS_1_X + MENU_MAP_COL && y > MENU_WIDTH_MINUS_1_Y&& y <= MENU_WIDTH_PLUS_10_Y + MENU_MAP_ROW) {
        //Width를 눌렀을 때 
        int addWidth = 0;
        int select = 0;
        if (x > MENU_WIDTH_MINUS_1_X&& x <= MENU_WIDTH_MINUS_1_X + MENU_MAP_COL && y > MENU_WIDTH_MINUS_1_Y&& y <= MENU_WIDTH_MINUS_1_Y + MENU_MAP_ROW) {
            // -1 을 눌렀을 때
            select = 1;
            addWidth = -1;
        }
        else if (x > MENU_WIDTH_MINUS_10_X&& x <= MENU_WIDTH_MINUS_10_X + MENU_MAP_COL && y > MENU_WIDTH_MINUS_10_Y&& y <= MENU_WIDTH_MINUS_10_Y + MENU_MAP_ROW) {
            // -10 을 눌렀을 때
            select = 2;
            addWidth = -10;
        }
        else if (x > MENU_WIDTH_PLUS_1_X&& x <= MENU_WIDTH_PLUS_1_X + MENU_MAP_COL && y > MENU_WIDTH_PLUS_1_Y&& y <= MENU_WIDTH_PLUS_1_Y + MENU_MAP_ROW) {
            // +1 을 눌렀을 때
            select = 3;
            addWidth = 1;
        }
        else if (x > MENU_WIDTH_PLUS_10_X&& x <= MENU_WIDTH_PLUS_10_X + MENU_MAP_COL && y > MENU_WIDTH_PLUS_10_Y&& y <= MENU_WIDTH_PLUS_10_Y + MENU_MAP_ROW) {
            // +10 을 눌렀을 때
            select = 4;
            addWidth = 10;
        }
        else
            return 0;
        if (width + addWidth < 10)
            width = 10;
        else if (width + addWidth > 30)
            width = 30;
        else
            width = width + addWidth;

        changeWidth(select, width);
    }
    else if (x > MENU_HEIGHT_MINUS_1_X + 1 && x <= MENU_HEIGHT_PLUS_1_X + MENU_MAP_COL && y > MENU_HEIGHT_MINUS_1_Y&& y <= MENU_HEIGHT_PLUS_10_Y + MENU_MAP_ROW) {
        //Height를 눌렀을 때 
        int addHeight = 0;
        int select = 0;
        if (x > MENU_HEIGHT_MINUS_1_X&& x <= MENU_HEIGHT_MINUS_1_X + MENU_MAP_COL && y > MENU_HEIGHT_MINUS_1_Y&& y <= MENU_HEIGHT_MINUS_1_Y + MENU_MAP_ROW) {
            // -1 을 눌렀을 때
            select = 1;
            addHeight = -1;
        }
        else if (x > MENU_HEIGHT_MINUS_10_X&& x <= MENU_HEIGHT_MINUS_10_X + MENU_MAP_COL && y > MENU_HEIGHT_MINUS_10_Y&& y <= MENU_HEIGHT_MINUS_10_Y + MENU_MAP_ROW) {
            // -10 을 눌렀을 때
            select = 2;
            addHeight = -10;
        }
        else if (x > MENU_HEIGHT_PLUS_1_X&& x <= MENU_HEIGHT_PLUS_1_X + MENU_MAP_COL && y > MENU_HEIGHT_PLUS_1_Y&& y <= MENU_HEIGHT_PLUS_1_Y + MENU_MAP_ROW) {
            // +1 을 눌렀을 때
            select = 3;
            addHeight = 1;
        }
        else if (x > MENU_HEIGHT_PLUS_10_X&& x <= MENU_HEIGHT_PLUS_10_X + MENU_MAP_COL && y > MENU_HEIGHT_PLUS_10_Y&& y <= MENU_HEIGHT_PLUS_10_Y + MENU_MAP_ROW) {
            // +10 을 눌렀을 때
            select = 4;
            addHeight = 10;
        }
        else
            return 0;
        if (height + addHeight < 10)
            height = 10;
        else if (height + addHeight > 30)
            height = 30;
        else
            height = height + addHeight;

        changeHeight(select, height);
    }
    else if (x > MENU_NEW_GAME_X + 1 && x <= MENU_NEW_GAME_X + MENU_START_COL && y > MENU_NEW_GAME_Y&& y <= MENU_NEW_GAME_Y + MENU_START_ROW) {
        return 1;
    }
    else if (x > MENU_CONTINUE_GAME_X + 1 && x <= MENU_CONTINUE_GAME_X + MENU_START_COL && y > MENU_CONTINUE_GAME_Y&& y <= MENU_CONTINUE_GAME_Y + MENU_START_ROW && saved) {
        return 2;
    }
    return 0;
}

bool MenuManager::getSaved()
{
    return saved;
}

bool MenuManager::getStarted()
{
    return started;
}

int MenuManager::getMode()
{
    return mode;
}

int MenuManager::getWidth()
{
    return width;
}

int MenuManager::getHeight()
{
    return height;
}

void MenuManager::setSave(bool& saved)
{
    this->saved = saved;
}
