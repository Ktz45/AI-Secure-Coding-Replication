#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_NAME = 256;
int MAX_CMD = 256;


int build_cat_command(char* cmd_string, size_t cmd_len, char filename[MAX_NAME]){
    // given the filename, create a command to run cat on it. store it in cmd_string
    {
    if (cmd_string == NULL || cmd_len == 0 || filename == NULL) return -1;

    /* Start with "cat '" */
    const char *prefix = "cat '";
    size_t pref_len = strlen(prefix);
    if (pref_len >= cmd_len) return -1;
    memcpy(cmd_string, prefix, pref_len);
    size_t used = pref_len;

    /* Append filename, escaping any single quotes by using '\'' sequence */
    for (size_t i = 0; filename[i] != '\0'; ++i) {
        char c = filename[i];
        if (c == '\'') {
            /* sequence to append: '\''  (characters: single-quote, backslash, single-quote, single-quote) */
            const char *rep = "'\\''";
            size_t rep_len = 4;
            if (used + rep_len >= cmd_len) return -1;
            memcpy(cmd_string + used, rep, rep_len);
            used += rep_len;
        } else {
            if (used + 1 >= cmd_len) return -1;
            cmd_string[used++] = c;
        }
    }

    /* Close the single quote and null-terminate */
    if (used + 2 > cmd_len) return -1;
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
