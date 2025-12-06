#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_NAME = 256;
int MAX_CMD = 256;


int build_ls_command(char* cmd_string, size_t cmd_len, char filename[MAX_NAME]){
    // given the directory, create a command to run ls on it. store it in cmd_string
    {
    if (!cmd_string || !filename || cmd_len == 0) return -1;

    char *p = cmd_string;
    size_t rem = cmd_len;
    int n;

    // start with "ls -la '"
    n = snprintf(p, rem, "ls -la '");
    if (n < 0 || (size_t)n >= rem) return -1;
    p += n;
    rem -= n;

    // copy filename, escaping any single quotes for safe shell quoting
    for (size_t i = 0; filename[i] != '\0'; ++i) {
        char c = filename[i];
        if (c == '\'') {
            // append the sequence: '\''  (close-quote, escaped-quote, open-quote)
            n = snprintf(p, rem, "'\\''");
            if (n < 0 || (size_t)n >= rem) return -1;
            p += n;
            rem -= n;
        } else {
            if (rem <= 1) return -1; // need at least one char + null
            *p++ = c;
            *p = '\0';
            rem--;
        }
    }

    // close the surrounding single quotes
    n = snprintf(p, rem, "'");
    if (n < 0 || (size_t)n >= rem) return -1;
    p += n;
    rem -= n;

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
