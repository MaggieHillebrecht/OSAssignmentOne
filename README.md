# Programming Assignment One - System Call Interface
Margaret "Maggie" Hillebrecht
2455754
hillebrecht@chapman.edu

CPSC 380 Section 1

Joel Escobar
2429057
joescobar@chapman.edu

CPSC 380 Section 1

## Source Files:
* `fops_test.c`
* `fops.h`
* `libfops.a`
* `lobfops.c`
* `README.md`
* `example.txt`

## Build Instructions
```
gcc -c libfops.c
ar crv libfops.a libfops.o
gcc fops_test.c -o fops_test libfops.a
```

## Run Instructions
```
./fops_test <option> <filename> <text (optional)>
```

## References:
* `man 2 chmod` -- gave us the `fcntl.h` header file for `mode_t` data type
* `man 2 chmod` -- let us know to use `sys/stat.h` header file
* `man 3 errno` -- gave us the `errno.h` header file to include the `errno` variable
* `man 2 syscall` -- gave us the `unistd.h` header file to use the `size_t` and `ssize_t` data types
* `man 2 syscall` -- let us know to use `sys/sycall.h` header file
* https://medium.com/@joshuaudayagiri/linux-system-calls-read-a9ce7ed33827 -- Gave some more detail for `read()` and also helped to realize that you need to close the file when you finish reading.
* https://medium.com/@joshuaudayagiri/linux-system-calls-open-e194e6fe2395 -- Gave some more detail for `open()`
