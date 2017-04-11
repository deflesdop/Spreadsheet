#include "../include/sheet.h"
#include "../include/column.h"
#include <curses.h>

static const int lines(24);
static const int cols(80);

int main(void)
{
  /* Initialiseren */
  initscr();
  noecho();

  /* Maak een venster, grootte lines x cols */
  WINDOW *win = newwin(lines, cols, 0, 0);
  keypad(win, TRUE); /* Enable keypad input */

  /* Verplaats cursor rij 10, kolom 20 */
  wmove(win, 10, 20);
  /* Plaats een string */
  waddstr(win, "HELLO WORLD!!");

  /* Nogmaals, maar nu op een achtergrond */
  attr_t old_attr; /* Huidige settings onthouden */
  short old_pair;
  wattr_get(win, &old_attr, &old_pair, NULL);
  wattron(win, A_STANDOUT);
  wmove(win, 12, 20);
  waddstr(win, "HELLO WORLD!!!");
  wattr_set(win, old_attr, old_pair, NULL); /* Oude settings terugzetten */

  /* Wacht tot er op enter wordt gedrukt */
  int ch;
  while ((ch = wgetch(win)) != '\n');

  delwin(win);  /* Dealloceer venster */
  endwin();  /* Curses stoppen */

  return 0;
}


