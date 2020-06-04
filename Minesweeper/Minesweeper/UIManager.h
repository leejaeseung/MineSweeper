#pragma once
#include <memory>
#include "Map.h"
#include "config.h"
using std::unique_ptr;

class UIManager {
protected:
	int mode;
	int width;
	int height;
	bool saves[SAVE_MAX];
	
private:
	void printEasy(const int& color, const int& bgcolor);
	void printNormal(const int& color, const int& bgcolor);
	void printHard(const int& color, const int& bgcolor);
	void printWidthPlus1(const int& color, const int& bgcolor);
	void printWidthPlus10(const int& color, const int& bgcolor);
	void printWidthMinus1(const int& color, const int& bgcolor);
	void printWidthMinus10(const int& color, const int& bgcolor);
	void printWidth();
	void printHeightPlus1(const int& color, const int& bgcolor);
	void printHeightPlus10(const int& color, const int& bgcolor);
	void printHeightMinus1(const int& color, const int& bgcolor);
	void printHeightMinus10(const int& color, const int& bgcolor);
	void printHeight();
	void changeMode(const int& prevMode,const int& nextMode);
	void changeWidth(const int& select, const int& nextWidth);
	void changeHeight(const int& select, const int& nextHeight);
	void printNewGame();
	void printContinueGame(const int& color);

	void printGoMenu(const double& rate);
	void printSaves(const int& color, const int& bgcolor, const int& idx);

	void eraseConsole();
	
	void setColor(int color, int bgcolor);
	void gotoxy(const int& x, const int& y);
	void setCursorView(const bool& visible);
public:
	UIManager();
	~UIManager() = default;
	void printMenu(const bool& saved);
	void printMap(const Map& map);
	int menuProcess(const int& x, const int& y, const bool& saved);
	int gameProcess(const int& x, const int& y, const bool& end, int* saveIdx);
	void tightXY(int* x, int* y);
	void reset();
	int getMode();
	int getWidth();
	int getHeight();
};