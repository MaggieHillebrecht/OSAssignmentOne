#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "fops.h"

int main(int argc, char** argv){
    //Result variable is used see the status after the system called 
    //this helps us with specifying error handling
    int result;

    //Used an if statement in order to check each command instead of a switch statement
    //as we found this way to be more reliable and easier to implement
    if (strcmp(argv[1], "create") == 0) {
        //Checks to see if the number of arguments are correct in order to proceed with the system call
        if (argc != 3) {
            printf("Invalid amount of arguments. Exiting...\n");
            return -1;
        } else {
            result = createFile(argv[2], (O_CREAT | O_WRONLY | O_EXCL), (0744));
            /*Open() returns a nonnegative number if successful so checks for -1 if failed*/
            if (result < 0) {
                perror("Error creating file");
                return -1;
            }
        }
    }
    else if (strcmp(argv[1], "write") == 0) {
        /*Checks correct arg amount and then checks if the syscall was successful*/
        if (argc != 4) {
            printf("Invalid amount of arguments. Exiting...\n");
            return -1;
        } else {
            result = writeToFile(createFile(argv[2], (O_WRONLY), 644), argv[3], strlen(argv[3]));
            /*Write() returns the number of bytes written so checks for -1 which means syscall failed*/
            if (result < 0) {
                perror("Error writing to file");
                return -1;
            }
        }
    }
    else if (strcmp(argv[1], "read") == 0) {
        /*Checks correct arg amount and then checks if the syscall was successful*/
        if (argc != 3) {
            printf("Invalid amount of arguments. Exiting...\n");
            return -1;
        } else {
            char buffer[500];
            result = readFromFile(createFile(argv[2],O_RDONLY, 444), buffer, sizeof(buffer));
            /*Read() returns the number of bytes read so checks for -1 which means syscall failed*/
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
        /*Checks correct arg amount and then checks if the syscall was successful*/
        if (argc != 3) {
            printf("Invalid amount of arguments. Exiting...\n");
            return -1;
        } else {
            result = closeFile(createFile(argv[2],O_RDONLY, 444));
            /*Close() returns 0 if successful and -1 if failed so checks errors if != 0*/
            if (result != 0) {
                perror("Error closing the file");
                return -1;
            }
        }
    }
    else if (strcmp(argv[1], "delete") == 0) {
        /*Checks correct arg amount and then checks if the syscall was successful*/
        if (argc != 3) {
            printf("Invalid amount of arguments. Exiting...\n");
            return -1;
        } else {
            /*Unlink() returns 0 if successful and -1 if failed so checks errors if != 0*/
            if (deleteFile(argv[2]) != 0) {
                perror("Error closing file");
                return -1;
            }
        }
    }
    else {
        //This errno is a general error where it is set to invalid arguments
        errno = EINVAL;
        perror("Error");
        return -1;
    }
}