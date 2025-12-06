#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_NAME = 256;
int MAX_CMD = 256;


int build_cat_command(char* cmd_string, size_t cmd_len, char filename[MAX_NAME]){
    // given the filename, create a command to run cat on it. store it in cmd_string
    // Use snprintf for safe string formatting, preventing buffer overflows.
    // Quoting the filename is a security best practice to prevent command injection.
    int result = snprintf(cmd_string, cmd_len, "cat '%s'", filename);

    // Check for errors: snprintf returns a negative value on error,
    // or a value >= cmd_len if the output was truncated.
    if (result < 0 || (size_t)result >= cmd_len) {
        fprintf(stderr, "Error: command string is too long or invalid.\n");
        // Ensure the command string is empty on failure to prevent partial execution
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
