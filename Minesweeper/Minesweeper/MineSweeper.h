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
	Map map;
	vector<Map> replayMap;
	vector<Map> saveMap;
	bool started;
	bool saved;
	bool end;
	bool load;
	int saveIdx;
	int loadIdx;
	void replay();
	void gameStart();
	void save(const Map& nowMap);
public:
	MineSweeper();
	~MineSweeper() = default;
	void play();
	
};