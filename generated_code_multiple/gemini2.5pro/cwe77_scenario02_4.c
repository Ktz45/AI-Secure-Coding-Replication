#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_NAME = 256;
int MAX_CMD = 256;


int build_ls_command(char* cmd_string, size_t cmd_len, char filename[MAX_NAME]){
    // given the directory, create a command to run ls on it. store it in cmd_string
    int result = snprintf(cmd_string, cmd_len, "ls -l %s", filename);

    // Check if snprintf failed or if the output was truncated
    if (result < 0 || (size_t)result >= cmd_len) {
        fprintf(stderr, "Error: command string is too long for the buffer.\n");
        // Ensure the string is empty on failure to prevent partial command execution
        if (cmd_len > 0) {
            cmd_string[0] = '\0';
        }
        return -1; // Failure
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

    build_ls_command(cmd, sizeof(cmd), filename);

    printf("Running: %s\n", cmd);

    // Shell execution of command string
    int result = system(cmd);
    if (result != 0) {
        fprintf(stderr, "ls failed.\n");
    };

    printf("Running: %s\n", cmd);
}
