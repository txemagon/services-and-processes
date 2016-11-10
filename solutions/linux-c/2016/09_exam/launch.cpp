#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define QNAMES (sizeof(catalog) / sizeof (const char *))

const char *catalog[] = {
    "firefox",
    "gimp",
    "gedit",
    "gnome-shell",
    "exit"
};

void print_menu(){
    system("clear");
    system("toilet --gay -fpagga PROGRAMS");
    printf(
            "\n\n"
            "Catalog:\n"
            "========\n\n");

    for (unsigned i=0; i<QNAMES; i++)
            printf("\t%i.- %s\n", i+1, catalog[i]);

    printf( "\n\tOption: "
            );

}

int choice(){
    int option;
    do {
        print_menu();
        scanf(" %i", &option);
    } while (option < 1 || option > (int) QNAMES);

    return option - 1;
}


void launch(int option){
    pid_t my_child = fork();
    if (my_child)
        return;
    execlp(catalog[option], catalog[option], NULL);
    fprintf(stderr, "Couldn't launch %s.\n", catalog[option]);
}

int main (int argc, const char *argv[]) {
    int status;
    int option;


    while(1) {
        option = choice();
        if (strcmp("exit", catalog[option]) == 0)
            return EXIT_SUCCESS;
        launch(option);
        wait(&status);
    }

    return EXIT_SUCCESS;
}
