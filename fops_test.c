#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <errno.h>
#include <string.h>
#include "fops.h"

int main(int argc, char** argv){
    int result;
    /*
    Try catch, checking the first index of argv to see if it is create, write, read, close, delete
    
    save open call for fd parameter in read
    set up permissions for the file, set up as read write execute 0664 is the last argument

    Got help from ChatGPT in regards to debugging the static library creation, as well as how to go about debugging my read command not working
    https://chatgpt.com/share/67bceab2-322c-800f-b008-879983c94656
    */

   if (argc < 3) {
        errno = EINVAL;
        perror("");
        return -1;
    } else if (strcmp(argv[1], "create") == 0) {
        createFile(argv[2], (O_CREAT | O_WRONLY | O_TRUNC), (0744));
    }
    else if (strcmp(argv[1], "write") == 0) {
        int fd = createFile(argv[2], O_WRONLY, 0644);
        if (fd < 0) {
            perror("File creation failed");
            return -1;
        }
        writeToFile(fd, argv[3], strlen(argv[3]));
        closeFile(fd);
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
    } else if (strcmp(argv[1], "close") == 0) {
        int fd = createFile(argv[2], O_RDONLY, 0444);
        if (fd < 0) {
            perror("Failed to open file for closing");
            return -1;
        }
        closeFile(fd);
    }
    else if (strcmp(argv[1], "delete") == 0) {
        deleteFile(argv[2]);
    }
    else {
        perror(strerror(errno));
    }
}