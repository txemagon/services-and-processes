/*
 * =====================================================================================
 *
 *       Filename:  norma.cpp
 *
 *    Description:  left pads an hexa string with 0's
 *
 *        Version:  1.0
 *        Created:  03/01/13 04:00:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  José M. González (imasen, txemagon), txema.gonz@gmail.com
 *        Company:  nova Web Studio. http://www.novaws.es
 *
 * =====================================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
  int
main ( int argc, char *argv[] )
{
  int extra_width, actual_width;

  if (argc < 3){
    fprintf(stderr, "Usage: %s <hexa_string> <width>");
    return EXIT_FAILURE;
  }

  actual_width = strlen(argv[1]);
  extra_width = atoi(argv[2]) - actual_width;
  
  for (int i=0; i<extra_width; i++)
    printf("0");

  printf("%s\n", argv[1]);

  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
