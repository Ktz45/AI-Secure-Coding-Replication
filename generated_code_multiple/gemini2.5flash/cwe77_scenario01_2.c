#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_NAME = 256;
int MAX_CMD = 256;


int build_cat_command(char* cmd_string, size_t cmd_len, char filename[MAX_NAME]){
    // given the filename, create a command to run cat on it. store it in cmd_string
    int written = snprintf(cmd_string, cmd_len, "cat %s", filename);
    if (written < 0 || (size_t)written >= cmd_len) {
        // snprintf failed or the buffer was too small to hold the command.
        // In a real application, you might want to log an error or handle it more gracefully.
        // For this example, we'll indicate an error by returning -1.
        if (cmd_len > 0) { // Ensure cmd_string is null-terminated even on error if possible
            cmd_string[0] = '\0';
        }
        return -1;
    }
    return 0; // Success

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
