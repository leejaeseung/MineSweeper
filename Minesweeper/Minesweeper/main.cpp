#include "ljs.h"
#include "MineSweeper.h"
using namespace ljs;

int main(void) {
    system("mode con cols=125 lines=40");
	printName();

    MineSweeper MS;
    MS.play();

	return 0;
}