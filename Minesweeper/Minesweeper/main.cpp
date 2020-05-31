#include "ljs.h"
#include "Clicker.h"
#include "MenuManager.h"
//#include "MineSweeper.h"
using namespace ljs;


extern void setCursorView(const bool& visible);
extern void gotoxy(const int& x, const int& y);
extern void setColor(int color, int bgcolor);

int main(void) {
    system("mode con cols=125 lines=40");
	printName();

    Clicker clk;
    MenuManager MM;
    //MineSweeper MS;
    MM.printMenu();

    while (1)
    {

        auto clk_pos = clk.getPos();
        
        //printf("%d %d", clk_pos.first, clk_pos.second);
        switch (MM.process(clk_pos.first, clk_pos.second)) {
        case 0:
            break;
        case 1:

            break;
        case 2:

            break;
        default:
            break;
        }

      /* gotoxy(clk_pos.first, clk_pos.second);
       setColor(0, 120);
       printf(" ");
       Sleep(200);
       gotoxy(clk_pos.first, clk_pos.second);
       setColor(0, 0);
       printf(" ");*/
            
    }

	return 0;
}