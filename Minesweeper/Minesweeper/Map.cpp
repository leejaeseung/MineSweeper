#include "Map.h"
#include <memory.h>
using std::make_unique;

Map::Map(const int& mode, const int& width, const int& height)
    :mode(mode), width(width), height(height), mineCnt((double)(width* height)* ((double)mode / 10)), openCnt(0), allCnt(width* height), map(make_unique<unique_ptr<int[]>[]>(height))
{
    for (int i = 0; i < height; i++)
    {
        map[i] = make_unique<int[]>(width * 2);
        for (int j = 0; j < width * 2; j++)
        {
            map[i][j] = 0;
        }
    }

    for (int i = 0; i < mineCnt; i++)
    {
        int x = rand() % (width * 2);
        int y = rand() % height;

        if (map[y][x] == 10 || x % 2 == 1) {
            //가로는 한 칸이 2byte이므로 짝수 칸만 판단, 지뢰가 이미 있으면 다시 생성
            i--;
            continue;
        }

        map[y][x] = 10;
        map[y][x + 1] = 10;
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width * 2; j += 2)
        {
            if (map[i][j] != 10)
                map[i][j] = checkMine(j, i);
        }
    }
}

int Map::checkMine(const int& x, const int& y)
//한 칸을 기준으로 주변에 지뢰가 몇 개인지 체크.
{
    int cnt = 0;

    for (int i = 0; i < 8; i++)
    {
        int nx = x + mv_x[i];
        int ny = y + mv_y[i];

        if (nx < 0 || ny < 0 || nx >= width * 2 || ny >= height) continue;

        if (map[ny][nx] == 10)
            cnt++;
    }

    return cnt + 11;
}

void Map::end()
//게임이 끝났을 때 모든 지뢰를 밝혀줌.
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width * 2; j++)
        {
            if (map[i][j] == 10) {
                map[i][j] = -1;
                map[i][j + 1] = -1;
            }
        }
    }
}

Map::Map(const Map& m)
    :mode(m.mode), width(m.width), height(m.height), mineCnt(m.mineCnt), openCnt(m.openCnt), allCnt(m.allCnt), map(make_unique<unique_ptr<int[]>[]>(height))
{
    for (int i = 0; i < height; i++)
    {
        map[i] = make_unique<int[]>(width * 2);
        for (int j = 0; j < width * 2; j++)
        {
            map[i][j] = m[i][j];
        }
    }
}

int Map::click(const int& x, const int& y)
{
    if (map[y][x] == 10 || map[y][x + 1] == 10) {       //지뢰를 선택할 시
        end();
        return 3;
    }
    if (map[y][x] < 11)  return 0;  //이미 밝혀진 곳이라면
    map[y][x] -= 11;                //클릭한 곳을 밝혀줌.
    map[y][x + 1] -= 11;
    openCnt++;

    if (allCnt - openCnt == mineCnt) {
        // 클리어한 경우
        end();
        return 2;
    }

    if (map[y][x] == 0) {
        for (int i = 0; i < 8; i++)
        {
            int nx = x + mv_x[i];
            int ny = y + mv_y[i];

            if (nx < 0 || ny < 0 || nx >= width * 2 || ny >= height) continue;      //맵의 범위 밖으로 나가지 않게
            if (map[ny][nx] == 10)   continue;          //지뢰가 있는 곳은 탐색x
            click(nx, ny);
        }
    }
    return 1;   //하나라도 밝혔다면
}

unique_ptr<int[]>& Map::operator[](const int& idx) const
{
    if(idx >= 0 && idx < width)
        return map[idx];
    else {
        exit(0);
    }
}

Map& Map::operator=(const Map& myMap) noexcept
{
    if (this == &myMap)  return *this;

    mode = myMap.mode;
    width = myMap.width;
    height = myMap.height;
    mineCnt = myMap.mineCnt;
    openCnt = myMap.openCnt;
    allCnt = myMap.allCnt;

    map = make_unique<unique_ptr<int[]>[]>(height);
    for (int i = 0; i < height; i++)
    {
        map[i] = make_unique<int[]>(width * 2);
        for (int j = 0; j < width * 2; j++)
        {
            map[i][j] = myMap[i][j];
        }
    }

    return *this;
}

double Map::getAchiveRate() const
{
    //진행률을 반환
    return ((double)(openCnt) / (double)(allCnt - mineCnt)) * 100.0;
}

int Map::getWidth() const
{
    return width;
}

int Map::getHeight() const
{
    return height;
}
