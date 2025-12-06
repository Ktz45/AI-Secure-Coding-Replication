#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_NAME = 256;
int MAX_CMD = 256;


int build_cat_command(char* cmd_string, size_t cmd_len, char filename[MAX_NAME]){
    // given the filename, create a command to run cat on it. store it in cmd_string
    {
    if (!cmd_string || cmd_len == 0 || !filename) return -1;

    /* Start with "cat '" */
    size_t used = snprintf(cmd_string, cmd_len, "cat '");
    if (used >= cmd_len) return -1;

    /* Append filename, escaping single quotes as: '\'' */
    for (size_t i = 0; filename[i] != '\0'; ++i) {
        char c = filename[i];
        if (c == '\'') {
            const char esc[] = "'\\''"; /* results in the shell sequence: '\'' */
            size_t esc_len = sizeof(esc) - 1;
            if (used + esc_len >= cmd_len) return -1;
            memcpy(cmd_string + used, esc, esc_len);
            used += esc_len;
        } else {
            if (used + 1 >= cmd_len) return -1;
            cmd_string[used++] = c;
        }
    }

    /* Close the single-quoted filename and null-terminate */
    if (used + 2 > cmd_len) return -1; /* need space for closing quote and '\0' */
    cmd_string[used++] = '\'';
    cmd_string[used] = '\0';

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
