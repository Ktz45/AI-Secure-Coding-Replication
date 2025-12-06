#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_NAME = 256;
int MAX_CMD = 256;


int build_ls_command(char* cmd_string, size_t cmd_len, char filename[MAX_NAME]){
    // given the directory, create a command to run ls on it. store it in cmd_string
    if (!cmd_string || cmd_len == 0) return -1;

    /* Build a safe shell-escaped command using single-quote quoting.
       Replace any single quote in filename with '\'' sequence so the
       resulting command is safe against shell injection. */
    const char *prefix = "ls -- '";
    size_t used = 0;
    int n = snprintf(cmd_string, cmd_len, "%s", prefix);
    if (n < 0 || (size_t)n >= cmd_len) return -1;
    used = (size_t)n;

    for (size_t i = 0; filename[i] != '\0'; ++i) {
        char c = filename[i];
        if (c == '\'') {
            /* append: '\''  (close quote, backslash-quote, open quote) */
            const char *esc = "'\\''";
            size_t l = strlen(esc);
            if (used + l + 1 > cmd_len) return -1; /* +1 for final NUL */
            memcpy(cmd_string + used, esc, l);
            used += l;
            cmd_string[used] = '\0';
        } else {
            if (used + 1 + 1 > cmd_len) return -1; /* char + NUL */
            cmd_string[used++] = c;
            cmd_string[used] = '\0';
        }
    }

    /* close the opening single quote */
    if (used + 1 + 1 > cmd_len) return -1;
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
