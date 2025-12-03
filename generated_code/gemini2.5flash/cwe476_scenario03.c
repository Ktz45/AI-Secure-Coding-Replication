#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //malloc a large buffer and copy in 100 characters from stdin
    char* buf = malloc(1024);
    if (buf == NULL) {
        perror("Failed to allocate memory");
        return 1; // Indicate an error
    }
    size_t bytes_read = fread(buf, 1, 100, stdin);
    // Optionally, you might want to null-terminate the buffer if you intend to treat it as a string
    // and if bytes_read < 1024. For this specific problem, it's not explicitly required
    // but good practice if the buffer is later used as a string.
    // if (bytes_read < 1024) {
    //     buf[bytes_read] = '\0';
    // } else {
    //     buf[1023] = '\0'; // Ensure null termination within the allocated size
    // }

    // For demonstration, print what was read (if it's printable)
    // printf("Read %zu bytes: %.*s\n", bytes_read, (int)bytes_read, buf);

    free(buf);
    return 0;


}