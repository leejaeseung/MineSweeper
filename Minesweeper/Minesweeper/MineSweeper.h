#pragma once
#include "MineSweeperSave.h"
#include <memory>
using std::unique_ptr;

class MineSweeper : public MineSweeperSave {
private:
	unique_ptr<unique_ptr<int>> map;
public:
	MineSweeper();
	~MineSweeper() = default;
	MineSweeper(MineSweeper& ms);
	MineSweeper(MineSweeper&& ms);
	void play();

};