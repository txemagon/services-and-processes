#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ncursesw/curses.h>
#include "sprites.h"

#define ESC 27
#define SQUID 0

  int
main ( int argc, char *argv[] )
{
  int inner = 0; // inner animation

  setlocale(LC_ALL, "");
  initscr();
  keypad(stdscr, TRUE);
  halfdelay(10);
  curs_set(0);
  while(getch() != ESC){
    for (int line=0; line<4; line++)
      for (int al=0; al<3; al++)
      mvprintw( 10 + line, 10 + al * 10, "%s", alien[al][inner % 2][line]);
    inner++;
    refresh();
  }
  curs_set(1);
  endwin();
  return EXIT_SUCCESS;
}
