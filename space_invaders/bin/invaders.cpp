#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ncursesw/curses.h>
#include "sprites.h"

#define ESC 27
#define SQUID 0
#define ALIENS_PER_LINE 8
#define ALIENS_PER_COL 5

void clean_up(){
  curs_set(1);
  endwin();
}
void init(){
  setlocale(LC_ALL, "");
  initscr();
  if (COLS<84){
    fprintf(stderr, "You need at least 84 columns.\n");
    clean_up();
    exit(EXIT_FAILURE);
  }
  keypad(stdscr, TRUE);
  halfdelay(10);
  curs_set(0);
}

int main ( int argc, char *argv[] ) {
  int inner = 0; // inner animation
  char alien_scr[ALIENS_PER_COL][ALIENS_PER_LINE];

  for(int row = 0; row<ALIENS_PER_COL; row++)
    for(int col = 0; col<ALIENS_PER_LINE; col++)
      alien_scr[row][col] = (row + 1) / 2 + 1;
  init();
  while(getch() != ESC){
   for(int alien_row = 0; alien_row<ALIENS_PER_COL; alien_row++)
    for (int line=0; line<4; line++)
      for (int al=0; al<ALIENS_PER_LINE; al++)
      mvprintw( 3 + line + 5 * alien_row, 8 * al, "%s", alien[alien_scr[alien_row][al]-1][inner % 2][line]);
    inner++;
    refresh();
  }
  clean_up();
  return EXIT_SUCCESS;
}
