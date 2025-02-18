#include <unistd.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include "fops.h"

int main(int argc, char* argv){
    /*
    Try catch, checking the first index of argv to see if it is create, write, read, close, delete
    
    save open call for fd parameter in read
    set up permissions for the file, set up as read write execute 0664 is the last argument
    */

   switch (argv[1])
   {
   case 'create':
    createFile(argv[2], 1, open)
    break;

    case 'write':
    writeToFile(argv[2], argv[3], 1)
    break;

    case 'read':
    readFromFile(argv[2], buf, 1)
    break;

    case 'close':
    closeFile(argv[2])
    break;

    case 'delete':
    deleteFile(argv[2])
    break;
   
   default:
        strerror(errno)
    break;
   }
}