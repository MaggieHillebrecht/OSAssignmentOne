#include <unistd.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <errno.h>
#include "fops.h"

int main(int argc, char** argv){
    /*
    Try catch, checking the first index of argv to see if it is create, write, read, close, delete
    
    save open call for fd parameter in read
    set up permissions for the file, set up as read write execute 0664 is the last argument
    */

    if (argv[1] == "create") {
        createFile(argv[2], 1, SYS_open); // open?
    }
    else if (argv[1] == "write") {
        writeToFile(argv[2], argv[3], 1);
    }
    else if (argv[1] == "read") {
        readFromFile(argv[2], 0, 1);
    }
    else if (argv[1] == "close") {
        closeFile(argv[2]);
    }
    else if (argv[1] == "delete") {
        deleteFile(argv[2]);
    }
    else {
        strerror(errno);
    }

    /*
   switch (argv[1])
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