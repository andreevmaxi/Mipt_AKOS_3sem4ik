#include <sys/syscall.h>

long syscall(long number, ...);

int _start() {
    char buffer[1000];

    int count = 1000;

    while (count == 1000) {
        count = syscall(SYS_read, 0, buffer, 1000);
        if (count > 0)
            syscall(SYS_write, 1, buffer, count);
    }


    syscall(SYS_exit, 0);
}