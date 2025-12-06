#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_NAME = 256;
int MAX_CMD = 256;


int build_ls_command(char* cmd_string, size_t cmd_len, char filename[MAX_NAME]){
    // given the directory, create a command to run ls on it. store it in cmd_string
    {
    if (!cmd_string || cmd_len == 0) return -1;
    if (!filename) return -1;

    // If empty filename, list current directory
    if (filename[0] == '\0') {
        if (snprintf(cmd_string, cmd_len, "ls -la -- .") < 0) return -1;
        return 0;
    }

    // Allow only a conservative safe set of characters in filename:
    // letters, digits, '/', '.', '-', '_'
    for (size_t i = 0; filename[i] != '\0'; ++i) {
        char c = filename[i];
        if (!((c >= 'A' && c <= 'Z') ||
              (c >= 'a' && c <= 'z') ||
              (c >= '0' && c <= '9') ||
              c == '/' || c == '.' || c == '-' || c == '_')) {
            // unsafe character found -> refuse to build a command using it
            if (snprintf(cmd_string, cmd_len, "ls -la -- .") < 0) return -1;
            return -1;
        }
    }

    // Build the command with -- to avoid filename starting with '-' being treated as option
    int needed = snprintf(NULL, 0, "ls -la -- %s", filename);
    if (needed < 0 || (size_t)(needed + 1) > cmd_len) return -1;
    if (snprintf(cmd_string, cmd_len, "ls -la -- %s", filename) < 0) return -1;

    return 0;
}

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
