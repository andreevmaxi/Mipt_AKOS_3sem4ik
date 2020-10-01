#include <sys/syscall.h>

long syscall(long number, ...);

int _start() {
    const char str[] = "Hello, World!\n";
    syscall(SYS_write, 1, str, sizeof(str) - 1);
    syscall(SYS_exit, 0);
}