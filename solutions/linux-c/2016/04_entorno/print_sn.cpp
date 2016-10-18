#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *server_name = getenv("SERVER_NAME");

    if (server_name == NULL)
        server_name = "No tiene";

    printf(" %s\n", server_name);

    return EXIT_SUCCESS;
}

