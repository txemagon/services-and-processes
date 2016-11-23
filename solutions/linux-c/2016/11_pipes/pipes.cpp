#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* run as: % ./pipes > /dev/pts/XX */

void writer(const char *mssg, int times, FILE *out_tube) {
    const char *letter;

    for (letter=mssg; times>0; --times, letter=mssg)
        while (*letter != '\0'){
            fputc(*letter, out_tube);
            fprintf(stderr, "sending: %c\n", *letter);
            fflush(out_tube);
            letter++;
            usleep(100000);
        }
}

void reader(FILE *in_tube) {
    char c;

    while (!feof(in_tube) && !ferror(in_tube) && (c=fgetc(in_tube))){
        fputc(c, stdout);
        fputc('\a', stdout);
        fflush(stdout);
    }
}

int main(int argc, char *argv[]) {

    int fds[2];

    if (pipe(fds) == -1){
        fprintf(stderr, "Couldn't open file.\n");
        return EXIT_FAILURE;
    }

    pid_t child_pid = fork();


    if (child_pid) {
        close(fds[0]);
        writer("The World is a Vampire.\n", 5, fdopen(fds[1], "w"));
        close(fds[1]);
    } else {
        close(fds[1]);
        reader(fdopen(fds[0], "r"));
        close(fds[0]);
    }

    return EXIT_SUCCESS;
}

