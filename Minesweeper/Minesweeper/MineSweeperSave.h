#pragma once

class MineSweeperSave {
private:

public:
	MineSweeperSave();
	~MineSweeperSave();
	MineSweeperSave(MineSweeperSave& mss);
	MineSweeperSave(MineSweeperSave&& mss);
	virtual void play();
};