#include "MineSweeper.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
using std::make_unique;

#define NO_ACTION 0
#define NEW_GAME 1
#define CONTINUE_GAME 2

#define CLICK_MAP 1
#define CLICK_BACK_TO_MENU 2
#define CLICK_SAVE 3

#define OPEN_CELL 1
#define GAME_WIN 2
#define GAME_FAIL 3

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
            case NO_ACTION:
                //유효하지 않은 곳 클릭 시 or 게임이 종료되고 맵 클릭 시
                break;
            case CLICK_MAP:
                //맵 클릭
                UM.tightXY(&clk_pos.first, &clk_pos.second);
                //커서의 좌표를 맵쪽으로 맞춰줌.

                switch (map->click(clk_pos.first, clk_pos.second)) {
                    //클릭
                case NO_ACTION:
                    //이미 밝혀진 곳을 클릭했을 때
                    break;
                case OPEN_CELL:
                    UM.printMap(const_cast<Map&>(*map));
                    replayMap.push_back(*map);
                    break;
                case GAME_WIN:
                    //게임 클리어
                   
                    UM.printMap(const_cast<Map&>(*map));
                    UM.printEndMsg(true);

                    end = true;
                    replayMap.push_back(*map);
                    replay();
                    //리플레이
                    break;
                case GAME_FAIL:
                    //게임 패배
                    
                    UM.printMap(const_cast<Map&>(*map));
                    UM.printEndMsg(false);

                    end = true;
                    replayMap.push_back(*map);
                    replay();
                    //리플레이
                    break;
                }
                break;
            case CLICK_BACK_TO_MENU:
                //메뉴로 돌아감.
                started = false;
                UM.reset();
                UM.printMenu(saved);
                break;
            case CLICK_SAVE:

                break;
            default:
                break;
           }
        }
        else {
            switch (UM.menuProcess(clk_pos.first, clk_pos.second, saved)) {
            case NO_ACTION:
                break;
            case NEW_GAME:
                map.reset((new Map(UM.getMode(), UM.getWidth(), UM.getHeight())));
                //맵을 새로 만듬.
                gameStart();
                break;
            case CONTINUE_GAME:
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
