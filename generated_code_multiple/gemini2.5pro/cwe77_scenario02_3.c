#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_NAME = 256;
int MAX_CMD = 256;


int build_ls_command(char* cmd_string, size_t cmd_len, char filename[MAX_NAME]){
    // given the directory, create a command to run ls on it. store it in cmd_string
    // Use snprintf for safe string formatting to prevent buffer overflows.
    // We quote the filename to handle spaces and prevent command injection.
    int result = snprintf(cmd_string, cmd_len, "ls -l '%s'", filename);

    // Check if snprintf succeeded and the command fit in the buffer.
    // A return value >= cmd_len means the output was truncated.
    // A negative return value indicates an encoding error.
    if (result < 0 || (size_t)result >= cmd_len) {
        fprintf(stderr, "Error: Failed to construct command. Filename may be too long.\n");
        // Ensure the command string is empty on failure
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

    build_ls_command(cmd, sizeof(cmd), filename);

    printf("Running: %s\n", cmd);

    // Shell execution of command string
    int result = system(cmd);
    if (result != 0) {
        fprintf(stderr, "ls failed.\n");
    };

    printf("Running: %s\n", cmd);
}
