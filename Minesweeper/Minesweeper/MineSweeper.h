#pragma once
#include "UIManager.h"
#include "Clicker.h"
#include "Map.h"
#include <vector>
using std::unique_ptr;
using std::vector;

class MineSweeper{
private:
	UIManager UM;
	Clicker clk;
	unique_ptr<Map> map;
	vector<Map> replayMap;
	bool started;
	bool saved;
	bool end;
	int saveIdx;
	
public:
	MineSweeper();
	~MineSweeper() = default;
	void play();
	void replay();
	void gameStart();
};