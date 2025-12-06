#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_NAME = 256;
int MAX_CMD = 256;


int build_ls_command(char* cmd_string, size_t cmd_len, char filename[MAX_NAME]){
    // given the directory, create a command to run ls on it. store it in cmd_string
    if (!cmd_string || cmd_len == 0) return -1;

const char *name = (filename && filename[0]) ? filename : ".";

/* start command with a single-quoted filename to avoid many shell injections */
int n = snprintf(cmd_string, cmd_len, "ls -la -- '");
if (n < 0) return -1;
size_t used = (size_t)n;
if (used >= cmd_len) { cmd_string[cmd_len-1] = '\0'; return -1; }

/* append the filename, escaping any single quotes as '\'' */
for (size_t i = 0; name[i] != '\0'; ++i) {
    char c = name[i];
    if (c == '\'') {
        /* need to append: '\''  (4 characters: ' \ ' ') */
        if (used + 4 >= cmd_len) { cmd_string[cmd_len-1] = '\0'; return -1; }
        cmd_string[used++] = '\'';  /* close existing single quote */
        cmd_string[used++] = '\\';  /* backslash */
        cmd_string[used++] = '\'';  /* escaped single quote */
        cmd_string[used++] = '\'';  /* reopen single quote */
        cmd_string[used] = '\0';
    } else {
        if (used + 1 >= cmd_len) { cmd_string[cmd_len-1] = '\0'; return -1; }
        cmd_string[used++] = c;
        cmd_string[used] = '\0';
    }
}

/* close the outer single quote */
if (used + 1 >= cmd_len) { cmd_string[cmd_len-1] = '\0'; return -1; }
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
