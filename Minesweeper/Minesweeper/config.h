#pragma once
#include <windows.h>

//게임 진행 관련
#define CLICK_DELAY 250
#define MINE_COLOR 120
#define MINE_SHAPE "●"
#define BOMB_COLOR 96
#define BOMB_SHAPE "※"

//메뉴 글자 좌표
#define MENU_TITLE_X 2
#define MENU_TITLE_Y 1
#define MENU_LEVEL_X 2
#define MENU_LEVEL_Y 13
#define MENU_MAP_X 70
#define MENU_MAP_Y 13

//난이도 박스 좌표
#define MENU_EASY_X 2
#define MENU_EASY_Y 23
#define MENU_NORMAL_X 2
#define MENU_NORMAL_Y 27
#define MENU_HARD_X 2
#define MENU_HARD_Y 31
#define MENU_LEVEL_ROW 3
#define MENU_LEVEL_COL 45

//폰트, 배경 색 값
#define MENU_DEFAULT_BGCOLOR 0
#define MENU_DEFAULT_FCOLOR 7
#define MENU_CHOOSE_BGCOLOR 7
#define MENU_CHOOSE_FCOLOR 0
#define MENU_UNACTIVATE_BGCOLOR 0
#define MENU_UNACTIVATE_FCOLOR 8

//MAP 설정 박스 좌표
#define MENU_MAP_ROW 1
#define MENU_MAP_COL 6
#define MENU_WIDTH_START_X 60
#define MENU_WIDTH_START_Y 23
#define MENU_WIDTH_OUT_X (MENU_WIDTH_START_X + 12)
#define MENU_WIDTH_OUT_Y (MENU_WIDTH_START_Y + 3)
#define MENU_WIDTHBOX_X (MENU_WIDTH_START_X + 7)
#define MENU_WIDTHBOX_Y MENU_WIDTH_START_Y
#define MENU_WIDTH_MINUS_1_X MENU_WIDTH_START_X
#define MENU_WIDTH_MINUS_1_Y MENU_WIDTH_START_Y
#define MENU_WIDTH_MINUS_10_X MENU_WIDTH_START_X
#define MENU_WIDTH_MINUS_10_Y (MENU_WIDTH_START_Y + 2)
#define MENU_WIDTH_PLUS_1_X (MENU_WIDTH_START_X + 18)
#define MENU_WIDTH_PLUS_1_Y MENU_WIDTH_START_Y
#define MENU_WIDTH_PLUS_10_X (MENU_WIDTH_START_X + 18)
#define MENU_WIDTH_PLUS_10_Y (MENU_WIDTH_START_Y + 2)

#define MENU_HEIGHT_START_X 88
#define MENU_HEIGHT_START_Y 23
#define MENU_HEIGHT_OUT_X (MENU_HEIGHT_START_X + 13)
#define MENU_HEIGHT_OUT_Y (MENU_HEIGHT_START_Y + 3)
#define MENU_HEIGHTBOX_X (MENU_HEIGHT_START_X + 7)
#define MENU_HEIGHTBOX_Y MENU_HEIGHT_START_Y
#define MENU_HEIGHT_MINUS_1_X MENU_HEIGHT_START_X
#define MENU_HEIGHT_MINUS_1_Y MENU_HEIGHT_START_Y
#define MENU_HEIGHT_MINUS_10_X MENU_HEIGHT_START_X
#define MENU_HEIGHT_MINUS_10_Y (MENU_HEIGHT_START_Y + 2)
#define MENU_HEIGHT_PLUS_1_X (MENU_HEIGHT_START_X + 20)
#define MENU_HEIGHT_PLUS_1_Y MENU_HEIGHT_START_Y
#define MENU_HEIGHT_PLUS_10_X (MENU_HEIGHT_START_X + 20)
#define MENU_HEIGHT_PLUS_10_Y (MENU_HEIGHT_START_Y + 2)

//게임 시작 박스 좌표
#define MENU_START_ROW 3
#define MENU_START_COL 18
#define MENU_NEW_GAME_X 63
#define MENU_NEW_GAME_Y 30
#define MENU_CONTINUE_GAME_X 91
#define MENU_CONTINUE_GAME_Y 30

void setCursorView(const bool& visible)
{
    CONSOLE_CURSOR_INFO cursor = { 1, visible };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void gotoxy(const int& x, const int& y)
{
    COORD Pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void setColor(int color, int bgcolor)
{
    color &= 0xf;
    bgcolor &= 0xf;
    static HANDLE std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(std_output_handle, bgcolor << 4 | color);
}
