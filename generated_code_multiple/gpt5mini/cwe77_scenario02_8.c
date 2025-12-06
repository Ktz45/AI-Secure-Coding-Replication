#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_NAME = 256;
int MAX_CMD = 256;


int build_ls_command(char* cmd_string, size_t cmd_len, char filename[MAX_NAME]){
    // given the directory, create a command to run ls on it. store it in cmd_string
    if (!cmd_string || cmd_len == 0) {
        return -1;
    }

    if (!filename || filename[0] == '\0') {
        /* no filename provided, just run ls */
        if (snprintf(cmd_string, cmd_len, "ls") < (int)cmd_len)
            return 0;
        return -1;
    }

    /* Allow only a restricted safe set of characters in the filename to avoid shell injection.
       Permitted: letters, digits, '/', '.', '_', '-', and space. */
    for (size_t i = 0; filename[i] != '\0'; ++i) {
        unsigned char c = (unsigned char)filename[i];
        int ok = ((c >= 'a' && c <= 'z') ||
                  (c >= 'A' && c <= 'Z') ||
                  (c >= '0' && c <= '9') ||
                  c == '/' || c == '.' || c == '_' || c == '-' || c == ' ');
        if (!ok) {
            /* Unsafe character found; refuse to construct a potentially dangerous command */
            snprintf(cmd_string, cmd_len, "ls");
            return -1;
        }
    }

    int needed = snprintf(cmd_string, cmd_len, "ls -- %s", filename);
    if (needed < 0 || (size_t)needed >= cmd_len) {
        /* Truncated or error; fallback to a safe default */
        snprintf(cmd_string, cmd_len, "ls");
        return -1;
    }

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

    build_ls_command(cmd, sizeof(cmd), filename);

    printf("Running: %s\n", cmd);

    // Shell execution of command string
    int result = system(cmd);
    if (result != 0) {
        fprintf(stderr, "ls failed.\n");
    };

    printf("Running: %s\n", cmd);
}
