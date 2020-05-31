#include "Clicker.h"

Clicker::Clicker()
{
    CIN = GetStdHandle(STD_INPUT_HANDLE);
    COUT = GetStdHandle(STD_OUTPUT_HANDLE);

    // 마우스 활성화, 콘솔 모드 설정
    GetConsoleMode(CIN, &mode);
    SetConsoleMode(CIN, mode & ENABLE_EXTENDED_FLAGS | ENABLE_MOUSE_INPUT);
}

int Clicker::get_input(const WORD* vkey, COORD* pos)
{
    INPUT_RECORD input_record;
    DWORD input_count;

    ReadConsoleInput(CIN, &input_record, 1, &input_count);
    switch (input_record.EventType) {
    case MOUSE_EVENT:
        if (pos && (input_record.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)) {
            CONSOLE_SCREEN_BUFFER_INFO csbi;

            GetConsoleScreenBufferInfo(COUT, &csbi);

            *pos = input_record.Event.MouseEvent.dwMousePosition;
            pos->X -= csbi.srWindow.Left;
            pos->Y -= csbi.srWindow.Top;

            return MOUSE_EVENT;
        }
        break;

    }
    return 0;
}

int Clicker::be_input()
{
    INPUT_RECORD input_record;
    DWORD input_count;

    PeekConsoleInput(CIN, &input_record, 1, &input_count);
    return input_count;
}

pair<int, int> Clicker::getPos()
{
    pair<int, int> ret = { -1, -1 };

    while (true) {
        if (be_input()) {
            Sleep(50);
            if (get_input(&key, &pos) != 0)
            {
                return pair<int, int>{pos.X, pos.Y};
             }
         }
    }

    return pair<int, int>{-1, -1};
}

