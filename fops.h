#ifndef FOPS_H
#define FOPS_H

#include <unistd.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <fcntl.h>

int createFile(const char *filename, int flags, mode_t mode);

ssize_t writeToFile(int fd, const void *buf, size_t count);

ssize_t readFromFile(int fd, void *buf, size_t count);

int closeFile(int fd);

int deleteFile(const char *filename);

#endif // FOPS_H