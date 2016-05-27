#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "../headers/sqlite3.h"
#include "../headers/dbModule.h"
#include "../headers/director.h"
#include "../headers/list.h"
#include "../headers/xmlModule.h"
#include "../headers/http.h"
#include "../headers/socket.h"

#ifndef TRUE
#define TRUE
#endif // TRUE

int main(void) {

    // Begin work with sockets.
    lib_init();

    // Initialize server socket.
    socket_t *server = socket_new();
    socket_bind(server, 5000);
    socket_listen(server);

    // Create directors set.
    int directorsAmount = 5;
    director_t *directorsSet[100];
    for (int i = 0; i < 100; i++)
    {
        directorsSet[i] = director_new_empty();
    }
    xmlModule_parseDirector(directorsSet);

    // Create database entity.
    db_t *testDB = database_new(DATABASE_FILE_PATH);

    // Buffer for socket messages.
    char socketBuffer[10000];
    memset(socketBuffer, 0, 10000);

    while (TRUE)
    {
        socket_t *client = socket_accept(server);
        socket_read(client, socketBuffer, sizeof(socketBuffer));

        printf("%s", socketBuffer);

        http_request_t request = http_request_parse(socketBuffer);

        // if-else loop

        // end of if-else loop

        socket_free(client);
    }

    // At the end of the program, free allocated memory.
    socket_free(server);
    lib_free();

    // End of the program.
    return 0;
}
