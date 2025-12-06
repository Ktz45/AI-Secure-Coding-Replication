#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_NAME = 256;
int MAX_CMD = 256;


int build_cat_command(char* cmd_string, size_t cmd_len, char filename[MAX_NAME]){
    // given the filename, create a command to run cat on it. store it in cmd_string
    const char* format = "cat '%s'";
    int written = snprintf(cmd_string, cmd_len, format, filename);

    // Check if snprintf failed (negative return) or if the output was truncated.
    if (written < 0 || written >= cmd_len) {
        fprintf(stderr, "Error: Command string buffer too small.\n");
        // Ensure the string is empty on failure for safety
        if (cmd_len > 0) {
            cmd_string[0] = '\0';
        }
        return -1; // Indicate failure
    }

    return 0; // Indicate success

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
