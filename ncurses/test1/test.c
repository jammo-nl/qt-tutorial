#include <curses.h>
#include <ncurses.h>

int main()
{
WINDOW * mainwin;
mainwin = initscr();
mvwaddstr(mainwin,10,10,"C NCurses Tutorial");
refresh();
getch();
delwin(mainwin);
endwin();
exit(0);
}
 
 
