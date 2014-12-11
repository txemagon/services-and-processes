#include <stdio.h>
#include <stdlib.h>

const char *program[] = {
    "firefox",
    "gedit",
    "nautilus",
    NULL
};

int show_menu() {
    int option;

    system("clear");
    printf("\nOpciones:\n\n");
    for (int op=0; program[op]; op++)
	printf("\t%i.- %s\n", op + 1, program[op]);
    printf("\n\tSu opcion: ");
    scanf(" %i", &option);

    return option - 1;
}

int main(int argc, char *argv[]) {
    int option;
    option = show_menu();
    printf("\nSe ha arrancado %s\n\n", program[option]);
    system(program[option]);
    return EXIT_SUCCESS;
}

