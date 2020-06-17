#include "MineSweeper.h"
#include <time.h>

#define NO_ACTION 0
#define NEW_GAME 1
#define CONTINUE_GAME 2
#define LOAD_GAME 3
#define LOAD_CLOSE 4

#define CLICK_MAP 1
#define CLICK_BACK_TO_MENU 2
#define CLICK_SAVE 3

#define OPEN_CELL 1
#define GAME_WIN 2
#define GAME_FAIL 3

MineSweeper::MineSweeper()
    :started(false), saved(false), end(false), load(false), saveIdx(0), loadIdx(0)
{
    srand(time(NULL));
    saveMap.resize(SAVE_MAX);
}

void MineSweeper::play()
{
    while (1)
    {
        Sleep(20);
        auto clk_pos = clk.getPos();

        if (started) {
            switch (UM.gameProcess(clk_pos.first, clk_pos.second, end, &saveIdx)) {
            case NO_ACTION:
                //유효하지 않은 곳 클릭 시 or 게임이 종료되고 맵 클릭 시
                continue;
            case CLICK_MAP:
                //맵 클릭
                UM.tightXY(&clk_pos.first, &clk_pos.second);
                //커서의 좌표를 맵쪽으로 맞춰줌.

                switch (map.click(clk_pos.first, clk_pos.second)) {
                    //클릭
                case NO_ACTION:
                    //이미 밝혀진 곳을 클릭했을 때
                    continue;
                case OPEN_CELL:
                    UM.printMap(map);
                    continue;       //게임을 계속 진행
                case GAME_WIN:
                    //게임 클리어 : 클리어 메세지 출력
                   
                    UM.printMap(map);
                    UM.printEndMsg(true);
                    break;
                case GAME_FAIL:
                    //게임 패배 : 패배 메세지 출력
                    
                    UM.printMap(map);
                    UM.printEndMsg(false);
                    break;
                }
                //게임을 종료, 리플레이
                end = true;
                replay(map);
                continue;
            case CLICK_BACK_TO_MENU:
                //메뉴로 돌아감.
                started = false;
                UM.set(1, 10, 10);
                UM.printMenu(saved);
                continue;
            case CLICK_SAVE:
                save(map);
                break;
            default:
                break;
           }
        }
        else {
            switch (UM.menuProcess(clk_pos.first, clk_pos.second, saved, load, &loadIdx, saveMap)) {
            case NO_ACTION:
                continue;
            case NEW_GAME:
                map = Map(UM.getMode(), UM.getWidth(), UM.getHeight());
                //맵을 새로 만듬.
                break;
            case CONTINUE_GAME:
                //Continue 버튼을 누름 -> 불러올 맵들을 띄움
                load = true;
                UM.printLoad(saveMap);
                continue;
            case LOAD_GAME:
                map = saveMap[loadIdx];
                break;
            case LOAD_CLOSE:
                load = false;
                UM.printMenu(saved);
                continue;
            default:
                break;
            }
            gameStart();
            //게임 시작
        }
    }
}

void MineSweeper::replay(const Map& map)
{
    for (auto nowMap : map.getReplayMap()) {
        Sleep(1000);
        UM.printMap(nowMap);
    }
}

void MineSweeper::gameStart()
{
    started = true;
    end = false;
    load = false;
    UM.printMap(map);
}

void MineSweeper::save(const Map& nowMap)
{
    saved = true;
    saveMap[saveIdx] = nowMap;
}