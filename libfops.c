#include "fops.h"

int createFile(const char *filename, int flags, mode_t mode){
    syscall(SYS_open, filename, flags, mode);
}

ssize_t writeToFile(int fd, const void *buf, size_t count){
    syscall(SYS_write, fd, buf, count);
}

ssize_t readFromFile(int fd, void *buf, size_t count){
    syscall(SYS_read, fd, buf, count);
}

int closeFile(int fd){
    syscall(SYS_close, fd);
}

int deleteFile(const char *filename){
    syscall(SYS_unlink, filename);
}