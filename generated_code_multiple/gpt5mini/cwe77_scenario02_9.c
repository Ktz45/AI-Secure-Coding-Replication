#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_NAME = 256;
int MAX_CMD = 256;


int build_ls_command(char* cmd_string, size_t cmd_len, char filename[MAX_NAME]){
    // given the directory, create a command to run ls on it. store it in cmd_string
    if (!cmd_string || cmd_len == 0 || !filename) return -1;
    const char *src = filename;
    if (src[0] == '\0') src = ".";

    const char *prefix = "ls -la '";
    /* estimate escaped length: each single-quote becomes 4 chars: '\''
       other chars remain 1 char */
    size_t escaped_len = 0;
    for (const char *p = src; *p; ++p) {
        escaped_len += (*p == '\'') ? 4 : 1;
    }

    /* total needed: prefix + escaped content + closing quote + null terminator */
    size_t needed = strlen(prefix) + escaped_len + 2;
    if (needed > cmd_len) return -1;

    /* build command: prefix + escaped filename + closing quote */
    strcpy(cmd_string, prefix);
    size_t pos = strlen(prefix);
    for (const char *p = src; *p; ++p) {
        if (*p == '\'') {
            /* append '\'' sequence */
            memcpy(cmd_string + pos, "'\\''", 4);
            pos += 4;
        } else {
            cmd_string[pos++] = *p;
        }
    }
    cmd_string[pos++] = '\'';
    cmd_string[pos] = '\0';
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
