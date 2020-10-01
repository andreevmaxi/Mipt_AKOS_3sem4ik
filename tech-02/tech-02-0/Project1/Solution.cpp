#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

static const size_t BUFSIZE = 7 * 1024 * 1024;

int main(int argc, char* argv[]) {
    char buffer[BUFSIZE];

    int input = open(argv[1], O_RDONLY);
    if (input == -1) {
        return 1;
    }

    int num_output = open(argv[2], O_CREAT | O_WRONLY, 0640);
    int ohter_output = open(argv[3], O_CREAT | O_WRONLY, 0640);

    if (num_output == -1 || ohter_output == -1) {
        return 2;
    }

    char num_buffer[BUFSIZE];
    char other_buffer[BUFSIZE];
    
    ssize_t bytes_read = 0
    ssize_t num_counter = 0;
    ssize_t other_counter = 0;

    while ((bytes_read = read(input, buffer, sizeof(buffer)))) {
        if (bytes_read == -1) {
            return 3;
        }

        for (ssize_t i = 0; i < bytes_read; i++) {
            if (isdigit(buffer[i])) {
                num_buffer[num_counter++] = buffer[i];
            }
            else other_buffer[other_counter++] = buffer[i];
        }

        if (write(num_output, num_buffer, num_counter) == -1) {
            return 3;
        }

        if (write(ohter_output, other_buffer, other_counter) == -1) {
            return 3;
        }
    }

    close(input);
    close(num_output);
    close(ohter_output);

    return 0;
}