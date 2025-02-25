#include "fops.h"

int createFile(const char *filename, int flags, mode_t mode){
    return syscall(SYS_open, filename, flags, mode);
}

ssize_t writeToFile(int fd, const void *buf, size_t count){
    ssize_t result = syscall(SYS_write, fd, buf, count);
    closeFile(fd);
    return result;
}

ssize_t readFromFile(int fd, void *buf, size_t count){
    ssize_t result = syscall(SYS_read, fd, buf, count);
    closeFile(fd);
    return result;
}

int closeFile(int fd){
    return syscall(SYS_close, fd);
}

int deleteFile(const char *filename){
    return syscall(SYS_unlink, filename);
}