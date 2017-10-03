#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#define DEBUG(...) if (verbose) \
    fprintf(stderr, __VA_ARGS__);

const char *program_name;
int verbose = 0;

void
print_usage(FILE *out, int return_code)
{
    fprintf(out, "Usage: %s\n"
	         "        This program converts from any base to any base.\n"
		 "\n"
		 "Examples:\n"
		 "==========\n"
		 "convert -b2 34 => 10 0010\n"
		 "\n"
	        , program_name);

    exit(return_code);
}


int
main (int argc, char * const argv[])
{
    int next_option;
    int output_base;
    const char *short_options = "hb:v";
    const struct option long_options[] = {
	{ "help", 0, NULL, 'h'},
	{ "base", 1, NULL, 'b'},
	{ "verbose", 0, NULL, 'v'}
    };

  program_name = argv[0];

  do {
      next_option = getopt_long(argc, argv, short_options, long_options, NULL);
      switch (next_option)
      {
	  case 'h':
	      print_usage(stdout, EXIT_SUCCESS);
	      break;
	  case 'v':
	      verbose = 1;
	      break;

	 case 'b':
	      output_base = atoi(optarg);
	      DEBUG("Estableciendo la base de salida a %i\n", output_base);
	      break;

	 case '?':
	      print_usage(stderr, EXIT_FAILURE);
	      break;

	 case -1:
	      break;

	default:
	      abort();
      }
  } while (next_option != -1);

  /* Empieza el funcionamiento del programa */
      DEBUG("Funcionando en modo prólijo.\n");

  return EXIT_SUCCESS;
}

