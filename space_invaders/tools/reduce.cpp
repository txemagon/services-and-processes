/*
 * =====================================================================================
 *
 *       Filename:  reduce.cpp
 *
 *    Description:  Fits four blocks into a single unicode block.
 *                  █ 
 *                   █  => ▚
 *
 *        Version:  1.0
 *        Created:  03/01/13 11:27:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  José M. González (imasen, txemagon), txema.gonz@gmail.com
 *        Company:  nova Web Studio. http://www.novaws.es
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char *reduced_char[] = { " ", "▗", "▖", "▄", 
                               "▝", "▐", "▞", "▟", 
			       "▘", "▚", "▍", "▙", 
			       "▀", "▜", "▛", "█"
                             };

int original_size;

void unmask(unsigned char hexa, int pos, char *sprite){
  unsigned char mask = 0x08;

  if (hexa >= 'a')
    hexa = hexa - 'a' + 'A';
  if (hexa <= '9')
    hexa -= '0';
  else if (hexa >= 'A' && hexa <= 'Z')
    hexa = hexa - 'A' + 10;
  else   
    hexa = 0;

  for (int i=0; i<4; i++){
    *(sprite + 4 * pos + i) = !!(hexa & mask);
    mask >>= 1;
  }
}

int value(const char *sprite, int row, int col, int width){
  if (col >= width)
      return 0;
  if (row * width + col >= original_size)
    return 0;
  return *(sprite + row * width + col);
}

void display(const char *sprite, int width, int original_size){

  for (int row=0; row * width < original_size; row++){
    for (int col=0; col < width; col++)
      printf("%s", reduced_char[*(sprite + row * width + col)]);
    printf("\n");
  }

}

void display2(const char *sprite, int width, int original_size){

  for (int row=0; row * width < original_size; row++){
    for (int col=0; col < width; col++)
        printf("%i", *(sprite + row * width + col) ); 
    printf("\n");
  }
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
  int
main ( int argc, char *argv[] )
{
  char *sprite = NULL, *reduced;
  char *letter;
  int width;

  if (argc<3){
    fprintf(stderr, "%sUsage: %s <hexa_string> <width>", argv[0]);
    return EXIT_FAILURE;
  }

  letter = argv[1];
  width = atoi(argv[2]);

  original_size = strlen(argv[1]) * 4;
  sprite  = (char *) malloc(original_size);
  reduced = (char *) malloc(original_size / 4);
  memset(sprite, 0, original_size);

  for (int i=0; i<original_size/4; i++)  /* Reconstruct the image from hexa */
    unmask(*(letter+i), i, sprite);

  // display2(sprite, width, original_size);

  for (int row=0; row * width < original_size; row+=2) /* Reduce the image */
    for (int col=0, index=0; col < width; col+=2){
      index = value(sprite, row + 1, col + 1, width) * 1 +
	value(sprite, row + 1, col    , width) * 2 +
	value(sprite, row    , col + 1, width) * 4 +
	value(sprite, row    , col    , width) * 8;
      *(reduced + row /2 * width / 2 + col / 2) = index;
    }

  display(reduced, width / 2, original_size / 4);

  free(sprite);
  free(reduced);

  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
