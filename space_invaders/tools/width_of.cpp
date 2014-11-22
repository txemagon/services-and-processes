/*
 * =====================================================================================
 *
 *       Filename:  width_of.cpp
 *
 *    Description:  Figure out the width of a sprite 
 *
 *        Version:  1.0
 *        Created:  03/01/13 00:34:58
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
#include <sys/types.h>
#include <regex.h>

#define MAX 0x80

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  scans for the dashed line and counts dashes 
 * =====================================================================================
 */
  int
main ( int argc, char *argv[] )
{
  FILE *f;
  regex_t sprite_end;
  regmatch_t match;
  const char *pattern = "^-+";
  char line_buffer[MAX];
  int height = 0;
  int missing = true;
  
  if (argc<2){
    fprintf(stderr, "Usage: '%s <sprite_filename>', \n", argv[0]);
    return EXIT_FAILURE;
  }

  if (!(f = fopen(argv[1], "r"))){
    fprintf(stderr, "%s: bad file: '%s', \n", argv[0], argv[1]);
    return EXIT_FAILURE;
  }

  if (regcomp(&sprite_end, pattern, REG_EXTENDED)){
    fprintf(stderr, "%s: bad pattern: '%s', \n", argv[0], pattern);
    return EXIT_FAILURE;
  }

  do {
    if (fgets(line_buffer, MAX, f))
      height++;
    missing = regexec(&sprite_end, line_buffer, 1, &match, 0);
  } while(!feof(f) && missing );

  printf("%i\n", match.rm_eo - match.rm_so);
  fclose(f);

  return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
