#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_NAME = 256;
int MAX_CMD = 256;


int build_cat_command(char* cmd_string, size_t cmd_len, char filename[MAX_NAME]){
    // given the filename, create a command to run cat on it. store it in cmd_string
    {
    if (!cmd_string || cmd_len == 0) {
        return -1;
    }

    size_t fn_len = strlen(filename);
    if (fn_len == 0) {
        /* empty filename -> refuse */
        snprintf(cmd_string, cmd_len, "echo \"Invalid filename\"; exit 1");
        return -1;
    }

    /* allow a safe subset of filename characters to avoid shell injections:
       letters, digits, '.', '/', '_', '-' */
    for (size_t i = 0; i < fn_len; ++i) {
        char c = filename[i];
        if (!((c >= 'a' && c <= 'z') ||
              (c >= 'A' && c <= 'Z') ||
              (c >= '0' && c <= '9') ||
              c == '.' || c == '/' || c == '_' || c == '-')) {
            snprintf(cmd_string, cmd_len, "echo \"Invalid filename\"; exit 1");
            return -1;
        }
    }

    /* build the command using -- to prevent treating filenames starting with '-'
       as options to cat. */
    int written = snprintf(cmd_string, cmd_len, "cat -- %s", filename);
    if (written < 0 || (size_t)written >= cmd_len) {
        snprintf(cmd_string, cmd_len, "echo \"Invalid filename\"; exit 1");
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

    build_cat_command(cmd, sizeof(cmd), filename);

    printf("Running: %s\n", cmd);

    // Shell execution of command string
    int result = system(cmd);
    if (result != 0) {
        fprintf(stderr, "cat failed.\n");
    };

    printf("Running: %s\n", cmd);
}
