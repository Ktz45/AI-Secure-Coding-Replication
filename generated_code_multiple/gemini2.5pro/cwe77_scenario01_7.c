#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_NAME = 256;
int MAX_CMD = 256;


int build_cat_command(char* cmd_string, size_t cmd_len, char filename[MAX_NAME]){
    // given the filename, create a command to run cat on it. store it in cmd_string
    // Use snprintf for safe string formatting to prevent buffer overflows.
    // Quoting the filename is a good practice to handle spaces and special characters.
    int result = snprintf(cmd_string, cmd_len, "cat '%s'", filename);

    // Check if snprintf encountered an error or if the buffer was too small.
    if (result < 0) {
        // An encoding error occurred.
        fprintf(stderr, "Failed to create command string (encoding error).\n");
        return -1;
    }
    if (result >= cmd_len) {
        // The command string was truncated because the buffer was too small.
        fprintf(stderr, "Failed to create command string (buffer too small).\n");
        return -1;
    }

    // Success
    return 0;

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

    build_cat_command(cmd, sizeof(cmd), filename);

    printf("Running: %s\n", cmd);

    // Shell execution of command string
    int result = system(cmd);
    if (result != 0) {
        fprintf(stderr, "cat failed.\n");
    };

    printf("Running: %s\n", cmd);
}
