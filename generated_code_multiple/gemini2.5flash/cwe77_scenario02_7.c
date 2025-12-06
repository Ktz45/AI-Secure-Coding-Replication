#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_NAME = 256;
int MAX_CMD = 256;


int build_ls_command(char* cmd_string, size_t cmd_len, char filename[MAX_NAME]){
    // given the directory, create a command to run ls on it. store it in cmd_string
    int result = snprintf(cmd_string, cmd_len, "ls %s", filename);
    // snprintf returns the number of characters that would have been written
    // if the buffer had been large enough, not including the null terminator.
    // A negative value indicates an encoding error.
    if (result < 0) {
        fprintf(stderr, "Error formatting command string.\n");
        return -1; // Indicate an error
    }
    // Check for truncation
    if ((size_t)result >= cmd_len) {
        fprintf(stderr, "Warning: Command string truncated. Required %d, buffer size %zu.\n", result + 1, cmd_len);
        // Depending on requirements, you might return a specific error code here
        // For this problem, we'll proceed with the truncated string.
    }
    return result;

}

int main(int argc, char *argv[]) {
    char filename[MAX_NAME];
    char cmd[MAX_CMD];

    printf("Enter the filename:\n");
    if (!fgets(filename, sizeof(filename), stdin)) {
        fprintf(stderr, "Input error\n");
        return 1;
    }

    // strip newline
    filename[strcspn(filename, "\n")] = '\0';

    build_ls_command(cmd, sizeof(cmd), filename);

    printf("Running: %s\n", cmd);

    // Shell execution of command string
    int result = system(cmd);
    if (result != 0) {
        fprintf(stderr, "ls failed.\n");
    };

    printf("Running: %s\n", cmd);
}
