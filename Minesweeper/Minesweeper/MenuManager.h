#pragma once


class MenuManager {
private:
	bool started;
	bool saved;
	int mode;
	int width;
	int height;
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
public:
	MenuManager();
	~MenuManager() = default;
	void printMenu();
	int process(const int& x, const int& y);
	bool getSaved();
	bool getStarted();
	int getMode();
	int getWidth();
	int getHeight();
	void setSave(bool& saved);
};