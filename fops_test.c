#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "fops.h"

int main(int argc, char** argv){
    int result;
    /*
    Try catch, checking the first index of argv to see if it is create, write, read, close, delete
    
    save open call for fd parameter in read
    set up permissions for the file, set up as read write execute 0664 is the last argument
    */

    if (strcmp(argv[1], "create") == 0) {
        if (argc != 3) {
            printf("Invalid amount of arguments. Exiting...\n");
            return -1;
        } else {
            result = createFile(argv[2], (O_CREAT | O_WRONLY | O_EXCL), (0744));
            if (result < 0) {
                perror("Error creating file");
                return -1;
            }
        }
    }
    else if (strcmp(argv[1], "write") == 0) {
        if (argc != 4) {
            printf("Invalid amount of arguments. Exiting...\n");
            return -1;
        } else {
            result = writeToFile(createFile(argv[2], (O_WRONLY), 644), argv[3], strlen(argv[3]));
            if (result < 0) {
                perror("Error writing to file");
                return -1;
            }
        }
    }
    else if (strcmp(argv[1], "read") == 0) {
        if (argc != 3) {
            printf("Invalid amount of arguments. Exiting...\n");
            return -1;
        } else {
            char buffer[500];
            result = readFromFile(createFile(argv[2],O_RDONLY, 444), buffer, sizeof(buffer));
            if (result < 0) {
                perror("Error reading from file");
                return -1;
            }
            else {
                printf("%s\n", buffer);
            }
        }
    }
    else if (strcmp(argv[1], "close") == 0) {
        if (argc != 3) {
            printf("Invalid amount of arguments. Exiting...\n");
            return -1;
        } else {
            result = closeFile(createFile(argv[2],O_RDONLY, 444));
            if (result != 0) {
                perror("Error closing the file");
                return -1;
            }
        }
    }
    else if (strcmp(argv[1], "delete") == 0) {
        if (argc != 3) {
            printf("Invalid amount of arguments. Exiting...\n");
            return -1;
        } else {
            if (deleteFile(argv[2]) != 0) {
                perror("Error closing file");
                return -1;
            }
        }
    }
    else {
        errno = EINVAL;
        perror("Error");
        return -1;
    }
}