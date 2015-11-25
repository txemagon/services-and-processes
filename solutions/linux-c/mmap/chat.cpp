#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define LONG  0x10000
#define TWEET 0xFF
#define MAX   (LONG / (TWEET + 1))

int main(int argc, char *argv[]) {

    char *tweet;
    char buffer[TWEET];

    int fd = open("chat.log", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR );
    lseek(fd, LONG + 1, SEEK_SET);
    write(fd, "FIN", 4);
    lseek(fd, 0, SEEK_SET);

    tweet = (char *) mmap(0, LONG, PROT_WRITE, MAP_SHARED, fd, 0);

    for (int count=0; count<MAX; count++){
        printf("Tweet: ");
        bzero(buffer, TWEET+1);
        fgets(buffer, TWEET, stdin);
        int len = strlen(buffer);
        buffer[len] = '\n';
        memcpy(&tweet[count*TWEET], buffer, TWEET+1);
    }

    munmap(tweet, LONG);
    close (fd);

    return EXIT_SUCCESS;
}
