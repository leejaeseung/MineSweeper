#include "MineSweeper.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
using std::make_unique;

MineSweeper::MineSweeper()
    :started(false), saved(false), end(false), map(nullptr), saveIdx(0)
{
    srand(time(NULL));
}

void MineSweeper::play()
{
    while (1)
    {
        auto clk_pos = clk.getPos();

        if (started) {
            switch (UM.gameProcess(clk_pos.first, clk_pos.second, end, &saveIdx)) {
            case 0:
                //유효하지 않은 곳 클릭 시 or 게임이 종료되고 맵 클릭 시
                break;
            case 1:
                //맵 클릭
                UM.tightXY(&clk_pos.first, &clk_pos.second);
                //커서의 좌표를 맵쪽으로 맞춰줌.

                switch (map->click(clk_pos.first, clk_pos.second)) {
                    //클릭
                case 0:
                    break;
                case -1:
                    //게임이 종료됨.
                    UM.printMap(const_cast<Map&>(*map));
                    end = true;
                    replayMap.push_back(*map);
                    replay();
                    //리플레이
                    break;
                case 1:
                    UM.printMap(const_cast<Map&>(*map));
                    replayMap.push_back(*map);
                    break;
                
                }
                break;
            case -1:
                //메뉴로 돌아감.
                started = false;
                UM.reset();
                UM.printMenu(saved);
                break;
            case 2:

                break;
            default:
                break;
           }
        }
        else {
            switch (UM.menuProcess(clk_pos.first, clk_pos.second, saved)) {
            case 0:
                break;
            case 1:
                map.reset((new Map(UM.getMode(), UM.getWidth(), UM.getHeight())));
                //맵을 새로 만듬.
                gameStart();
                break;
            case 2:
                gameStart();
                break;
            default:
                break;
            }
        }
    }
}

void MineSweeper::replay()
{
    for (auto nowMap : replayMap) {
        Sleep(1000);
        UM.printMap(nowMap);
    }
}

void MineSweeper::gameStart()
{
    started = true;
    end = false;
    UM.printMap(const_cast<Map&>(*map));
    replayMap.clear();
    replayMap.push_back(*map);
}
