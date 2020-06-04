#include "UIManager.h"
#include <windows.h>
#include <iostream>
#include <iomanip>
using namespace std;

UIManager::UIManager()
    :mode(1), width(10), height(10)
{
    for (int i = 0; i < SAVE_MAX; i++)
    {
        saves[i] = false;
    }
    setCursorView(0);
    printMenu(false);
}

void UIManager::printMenu(const bool& saved)
{
    int x = MENU_TITLE_X, y = MENU_TITLE_Y;

    eraseConsole();

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



void UIManager::printEasy(const int& color, const int& bgcolor) {
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

void UIManager::printNormal(const int& color, const int& bgcolor) {
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

void UIManager::printHard(const int& color, const int& bgcolor) {
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

void UIManager::printWidthPlus1(const int& color, const int& bgcolor)
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

void UIManager::printWidthPlus10(const int& color, const int& bgcolor)
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

void UIManager::printWidthMinus1(const int& color, const int& bgcolor)
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

void UIManager::printWidthMinus10(const int& color, const int& bgcolor)
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

void UIManager::printWidth()
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

void UIManager::printHeightPlus1(const int& color, const int& bgcolor)
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

void UIManager::printHeightPlus10(const int& color, const int& bgcolor)
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

void UIManager::printHeightMinus1(const int& color, const int& bgcolor)
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

void UIManager::printHeightMinus10(const int& color, const int& bgcolor)
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

void UIManager::printHeight()
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

void UIManager::changeMode(const int& prevMode, const int& nextMode) {
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

void UIManager::changeWidth(const int& select, const int& nextWidth)
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

void UIManager::changeHeight(const int& select, const int& nextHeight)
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

void UIManager::printNewGame()
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

void UIManager::printContinueGame(const int& color)
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

void UIManager::printBoom()
{

    int x = END_MSG_X;
    int y = END_MSG_Y;

    gotoxy(x, y++);
    cout << " /$$$$$$$   /$$$$$$   /$$$$$$  /$$      /$$       /$$ /$$ /$$";
    gotoxy(x, y++);
    cout << "| $$__  $$ /$$__  $$ /$$__  $$| $$$    /$$$      | $$| $$| $$";
    gotoxy(x, y++);
    cout << "| $$  \\ $$| $$  \\ $$| $$  \\ $$| $$$$  /$$$$      | $$| $$| $$";
    gotoxy(x, y++);
    cout << "| $$$$$$$ | $$  | $$| $$  | $$| $$ $$/$$ $$      | $$| $$| $$";
    gotoxy(x, y++);
    cout << "| $$__  $$| $$  | $$| $$  | $$| $$  $$$| $$      |__/|__/|__/";
    gotoxy(x, y++);
    cout << "| $$  \\ $$| $$  | $$| $$  | $$| $$\\  $ | $$                  ";
    gotoxy(x, y++);
    cout << "| $$$$$$$/|  $$$$$$/|  $$$$$$/| $$ \\/  | $$       /$$ /$$ /$$";
    gotoxy(x, y++);
    cout << "|_______/  \\______/  \\______/ |__/     |__/      |__/|__/|__/";
}

void UIManager::printClear()
{

    int x = END_MSG_X;
    int y = END_MSG_Y;

    gotoxy(x, y++);
    cout << "  /$$$$$$  /$$       /$$$$$$$$  /$$$$$$  /$$$$$$$        /$$ /$$ /$$";
    gotoxy(x, y++);
    cout << " /$$__  $$| $$      | $$_____/ /$$__  $$| $$__  $$      | $$| $$| $$";
    gotoxy(x, y++);
    cout << "| $$  \\__/| $$      | $$      | $$  \\ $$| $$  \\ $$      | $$| $$| $$";
    gotoxy(x, y++);
    cout << "| $$      | $$      | $$$$$   | $$$$$$$$| $$$$$$$/      | $$| $$| $$";
    gotoxy(x, y++);
    cout << "| $$      | $$      | $$__/   | $$__  $$| $$__  $$      |__/|__/|__/";
    gotoxy(x, y++);
    cout << "| $$    $$| $$      | $$      | $$  | $$| $$  \\ $$                  ";
    gotoxy(x, y++);
    cout << "|  $$$$$$/| $$$$$$$$| $$$$$$$$| $$  | $$| $$  | $$       /$$ /$$ /$$";
    gotoxy(x, y++);
    cout << " \\______/ |________/|________/|__/  |__/|__/  |__/      |__/|__/|__/";
}

void UIManager::printGoMenu(const double& rate)
{
    int x = MAP_BACK_TO_MENU_X;
    int y = MAP_BACK_TO_MENU_Y;

    gotoxy(x, y++);
    cout << "┌ㅡㅡㅡㅡㅡㅡ┬ㅡㅡㅡㅡㅡ┐";
    gotoxy(x, y++);
    cout.precision(2);
    cout << "ㅣ  M E N U  ㅣ " << setw(6) << fixed << rate << " %ㅣ";
    gotoxy(x, y++);
    cout << "└ㅡㅡㅡㅡㅡㅡ┴ㅡㅡㅡㅡㅡ┘";
}

void UIManager::printSaves(const int& color, const int& bgcolor, const int& idx)
{
    setColor(color, bgcolor);
    cout << " S A V E " << idx << " ";
}

void UIManager::printMap(const Map& map)
{
    eraseConsole();

    printGoMenu(map.getAchiveRate());

    int x = MAP_SAVE_X;
    int y = MAP_SAVE_Y;

    for (int i = 0; i < SAVE_MAX; i++)
    {
        gotoxy(x, y++);
        cout << "├ㅡㅡㅡㅡㅡㅡ┤";
        gotoxy(x, y++);
        cout << "ㅣ";
        if (saves[i])
            printSaves(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR, i);
        else
            printSaves(MENU_UNACTIVATE_FCOLOR, MENU_UNACTIVATE_BGCOLOR, i);
        setColor(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR);
        cout << "ㅣ";
    }
    gotoxy(x, y);
    cout << "└ㅡㅡㅡㅡㅡㅡ┘";

    gotoxy(MAP_X - width - 1, MAP_Y - (height / 2) - 1);
    cout << "┌";
    for (int i = 0; i < width; i++)
    {
        cout << "ㅡ";
    }
    cout << "-┐";

    for (int i = 0; i < height; i++)
    {
        gotoxy(MAP_X - width - 1, i + MAP_Y - (height / 2));
        cout << "ㅣ";
        for (int j = 0; j < width * 2; j += 2)
        {
            gotoxy(j + MAP_X - width, i + MAP_Y - (height / 2));
            if (map[i][j] >= 10) {
                cout << DEFAULT_SHAPE;
            }
            else if (map[i][j] == 0) {
                cout << "  ";
            }
            else if (map[i][j] == -1) {
                cout << BOMB_SHAPE;
            }
            else {
                cout << map[i][j] << " ";
            }
        }
        cout << "ㅣ";
    }
    gotoxy(MAP_X - 1 - width, MAP_Y + height - (height / 2));
    cout << "└";
    for (int i = 0; i < width; i++)
    {
        cout << "ㅡ";
    }
    cout << "-┘";
}

void UIManager::printEndMsg(const bool& win)
{
    Sleep(750);
    for (int i = 0; i < 3; i++)
    {
        eraseConsole();
        Sleep(200);
        if (win) {
            printClear();
        }
        else {
            printBoom();
        }
        Sleep(350);
    }
    
}

void UIManager::eraseConsole()
{
    for (int i = 1; i < 40; i++) {
        gotoxy(0, i);
        printf("%125c", ' ');
    }
}

void UIManager::setColor(int color, int bgcolor)
{
    color &= 0xf;
    bgcolor &= 0xf;
    static HANDLE std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(std_output_handle, bgcolor << 4 | color);
}

void UIManager::gotoxy(const int& x, const int& y)
{
    COORD Pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void UIManager::setCursorView(const bool& visible)
{
    CONSOLE_CURSOR_INFO cursor = { 1, visible };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

int UIManager::menuProcess(const int& x, const int& y, const bool& saved)
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

int UIManager::gameProcess(const int& x, const int& y, const bool& end, int* saveIdx)
{
    if (x > MAP_X - width && x <= MAP_X + width + 1 && y > MAP_Y - (height / 2) - 1 && y <= MAP_Y + (height / 2) - 1) {
        if (end) return 0;  //게임이 끝났다면 맵을 클릭해도 반응x
        return 1;
    }
    else if (x > MAP_BACK_TO_MENU_X&& x <= MAP_BACK_TO_MENU_X + MAP_MENU_COL && y > MAP_BACK_TO_MENU_Y&& y <= MAP_BACK_TO_MENU_Y + MAP_MENU_ROW) {
        //메뉴로 돌아가기 버튼
        return 2;
    }
    else if (x > MAP_SAVE_X&& x <= MAP_SAVE_X + MAP_MENU_COL && y > MAP_SAVE_Y&& y <= MAP_SAVE_Y + (MAP_MENU_ROW + 1) * SAVE_MAX - 1) {
        //세이브 버튼들 클릭
        if (end) return 0;          //게임이 끝났다면 저장을 클릭해도 반응x
        for (int i = 0; i < SAVE_MAX; i++)
        {
            if (y > MAP_SAVE_Y + i * 2 && y <= MAP_SAVE_Y + (i + 1) * 2 - 1) {
                *saveIdx = i;
                gotoxy(MAP_SAVE_X + 2, MAP_SAVE_Y + (i + 1) * 2 - 1);
                printSaves(MENU_CHOOSE_FCOLOR, MENU_CHOOSE_BGCOLOR, i);
                Sleep(CLICK_DELAY);
                gotoxy(MAP_SAVE_X + 2, MAP_SAVE_Y + (i + 1) * 2 - 1);
                printSaves(MENU_DEFAULT_FCOLOR, MENU_DEFAULT_BGCOLOR, i);
                break;
            }
        }
        return 3;
    }
    return 0;
}

void UIManager::tightXY(int* x, int* y)
{
    if ((MAP_X - width + 1) % 2 == 0) {
        if ((*x) % 2 == 1)
            (*x)--;
    }
    else {
        if ((*x) % 2 == 0)
            (*x)--;
    }
    *x -= (MAP_X - width + 1);
    *y -= (MAP_Y - (height / 2));
}

void UIManager::reset()
{
    this->mode = 1;
    this->width = 10;
    this->height = 10;
}

int UIManager::getMode()
{
    return mode;
}

int UIManager::getWidth()
{
    return width;
}

int UIManager::getHeight()
{
    return height;
}
