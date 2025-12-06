#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_NAME = 256;
int MAX_CMD = 256;


int build_ls_command(char* cmd_string, size_t cmd_len, char filename[MAX_NAME]){
    // given the directory, create a command to run ls on it. store it in cmd_string
    if (!cmd_string || cmd_len == 0) return -1;
    const char *prefix = "ls -la -- '";
    size_t used = snprintf(cmd_string, cmd_len, "%s", prefix);
    if (used >= cmd_len) return -1; // truncated or no space

    for (size_t i = 0; filename[i] != '\0'; ++i) {
        char c = filename[i];
        if (c == '\'') {
            /* append the shell-safe sequence '\'' which closes the single-quote,
               inserts an escaped single-quote, and reopens the single-quote */
            const char *esc = "'\\''"; /* produces: '\'' */
            size_t esc_len = strlen(esc);
            if (used + esc_len >= cmd_len) return -1;
            memcpy(cmd_string + used, esc, esc_len);
            used += esc_len;
            cmd_string[used] = '\0';
        } else {
            if (used + 1 >= cmd_len) return -1;
            cmd_string[used++] = c;
            cmd_string[used] = '\0';
        }
    }

    /* close the final single quote */
    if (used + 1 >= cmd_len) return -1;
    cmd_string[used++] = '\'';
    cmd_string[used] = '\0';

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
