#include <getopt.h>
#include <stdlib.h>


int
main ()
{
    const char *short_options = "hb:v";
    const struct option long_options = {
	{ "help", 0, NULL, 'h'},
	{ "base", 1, NULL, 'h'},
	{ "help", 0, NULL, 'h'},

  return EXIT_SUCCESS;
}

