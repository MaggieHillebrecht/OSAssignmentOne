#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <errno.h>
#include <string.h>
#include "fops.h"

int main(int argc, char** argv){
    /*
    Try catch, checking the first index of argv to see if it is create, write, read, close, delete
    
    save open call for fd parameter in read
    set up permissions for the file, set up as read write execute 0664 is the last argument
    */

   if (argc < 3) {
        errno = EINVAL;
        perror("");
        return -1;
    } else if (strcmp(argv[1], "create") == 0) {
        createFile(argv[2], (O_CREAT | O_WRONLY | O_TRUNC), (0744));
    }
    else if (strcmp(argv[1], "write") == 0) {
        // writeToFile(argv[2], argv[3], 1);
        writeToFile(createFile(argv[2], (O_WRONLY), 0644), argv[3], strlen(argv[3]));
    }
    else if (strcmp(argv[1], "read") == 0) {
        // readFromFile(argv[2], "", 1);
        char buffer[500];
        readFromFile(createFile(argv[2],O_RDONLY, 0444), buffer, 5000);
        printf("%s\n", buffer);
    }
    else if (strcmp(argv[1], "close") == 0) {
        closeFile(createFile(argv[2], O_RDONLY, 0444));
        // closeFile(argv[2]);
    }
    else if (strcmp(argv[1], "delete") == 0) {
        deleteFile(argv[2]);
    }
    else {
        perror(errno);
    }

   /*switch (argv[1])
   {
   case 'create':
    createFile(argv[2], 1, open);
    break;

    case 'write':
    writeToFile(argv[2], argv[3], 1);
    break;

    case 'read':
    readFromFile(argv[2], buf, 1);
    break;

    case 'close':
    closeFile(argv[2]);
    break;

    case 'delete':
    deleteFile(argv[2]);
    break;
   
   default:
        strerror(errno);
    break;
   }
   */
}