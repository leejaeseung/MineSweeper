#pragma once
#include <windows.h>
#include <utility>
using std::pair;

class Clicker {
private:
    HANDLE COUT = 0;
    HANDLE CIN = 0;
    DWORD md;
    WORD key;
    COORD pos;
    int get_input(const WORD* vkey, COORD* pos);
    int be_input();
public:
    Clicker();
    ~Clicker() = default;
    pair<int, int> getPos();
};