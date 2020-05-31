#pragma once

class MapCreator {
private:

public:
	MapCreator();
	~MapCreator();
	MapCreator(MapCreator& mc);
	MapCreator(MapCreator&& mc);
};