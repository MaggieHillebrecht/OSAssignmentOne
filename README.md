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
`fops_test.c`
`fops.h`
`libfops.a`
`lobfops.c`
`README.md`
`example.txt`

## References:
* `man 2 chmod` -- gave us the `fcntl.h` header file for `mode_t` data type
* `man 2 chmod` -- let us know to use `sys/stat.h` header file
* `man 3 errno` -- gave us the header file to include the `errno` variable
* `man 2 syscall` -- gave us the `unistd.h` header file to use the `size_t` and `ssize_t` data types
* `man 2 syscall` -- let us know to use `sys/sycall.h` header file