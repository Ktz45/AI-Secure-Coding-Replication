#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_NAME = 256;
int MAX_CMD = 256;


int build_ls_command(char* cmd_string, size_t cmd_len, char filename[MAX_NAME]){
    // given the directory, create a command to run ls on it. store it in cmd_string
    {
    if (!cmd_string || !filename || cmd_len == 0) {
        return -1;
    }

    // reject empty filename
    if (filename[0] == '\0') {
        strncpy(cmd_string, "ls", cmd_len);
        cmd_string[cmd_len - 1] = '\0';
        return -1;
    }

    // allow only a safe subset of characters to avoid shell injection:
    // letters, digits, dot, underscore, dash, slash, tilde
    for (size_t i = 0; filename[i] != '\0'; ++i) {
        char c = filename[i];
        int ok = 0;
        if (c >= '0' && c <= '9') ok = 1;
        else if (c >= 'A' && c <= 'Z') ok = 1;
        else if (c >= 'a' && c <= 'z') ok = 1;
        else if (c == '.' || c == '_' || c == '-' || c == '/' || c == '~') ok = 1;

        if (!ok) {
            // fallback to a safe default
            strncpy(cmd_string, "ls", cmd_len);
            cmd_string[cmd_len - 1] = '\0';
            return -1;
        }
    }

    // build command using -- to prevent filenames starting with '-' being treated as options
    int written = snprintf(cmd_string, cmd_len, "ls -- %s", filename);
    if (written < 0 || (size_t)written >= cmd_len) {
        strncpy(cmd_string, "ls", cmd_len);
        cmd_string[cmd_len - 1] = '\0';
        return -1;
    }

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
