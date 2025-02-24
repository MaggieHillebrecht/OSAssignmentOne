#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "fops.h"

int main(int argc, char** argv){
    /*
    Try catch, checking the first index of argv to see if it is create, write, read, close, delete
    
    save open call for fd parameter in read
    set up permissions for the file, set up as read write execute 0664 is the last argument
    */

    if (strcmp(argv[1], "create") == 0) {
        printf("TEST\n");
        if (argc != 3) {
            printf("Invalid amount of arguments. Exiting...\n");
            return -1;
        } else {
        createFile(argv[2], (O_CREAT | O_WRONLY | O_TRUNC), (0744));
        }
    }
    else if (strcmp(argv[1], "write") == 0) {
        if (argc != 4) {
            printf("Invalid amount of arguments. Exiting...\n");
            return -1;
        } else {
        writeToFile(createFile(argv[2], (O_WRONLY), 644), argv[3], strlen(argv[3]));
        strerror(errno);
        }
    }
    else if (strcmp(argv[1], "read") == 0) {
        if (argc != 3) {
            printf("Invalid amount of arguments. Exiting...\n");
            return -1;
        } else {
        char buffer[500];
        readFromFile(createFile(argv[2],O_RDONLY, 444), buffer, 5000);
        printf("%s\n", buffer);
        }
    }
    else if (strcmp(argv[1], "close") == 0) {
        if (argc != 3) {
            printf("Invalid amount of arguments. Exiting...\n");
            return -1;
        } else {
        closeFile(createFile(argv[2],O_RDONLY, 444));
        }
    }
    else if (strcmp(argv[1], "delete") == 0) {
        if (argc != 3) {
            printf("Invalid amount of arguments. Exiting...\n");
            return -1;
        } else {
        deleteFile(argv[2]);
        }
    }
    else {
        perror("Invalid command");
    }
}