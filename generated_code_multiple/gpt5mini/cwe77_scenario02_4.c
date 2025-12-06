#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_NAME = 256;
int MAX_CMD = 256;


int build_ls_command(char* cmd_string, size_t cmd_len, char filename[MAX_NAME]){
    // given the directory, create a command to run ls on it. store it in cmd_string
    {
    const char *prefix = "ls -- '";
    const char *suffix = "'";
    size_t pos = 0;

    if (!cmd_string || cmd_len == 0) return -1;

    /* copy prefix */
    size_t plen = strlen(prefix);
    if (plen + 1 > cmd_len) return -1;
    memcpy(cmd_string + pos, prefix, plen);
    pos += plen;

    /* copy filename, escaping any single quotes with: '\'' */
    for (size_t i = 0; filename[i] != '\0'; ++i) {
        char c = filename[i];
        if (c == '\'') {
            /* need four characters: '\''  ->  close-quote, backslash, single-quote, open-quote */
            if (pos + 4 + 1 > cmd_len) { cmd_string[0] = '\0'; return -1; }
            cmd_string[pos++] = '\'';  /* close current single-quoted string */
            cmd_string[pos++] = '\\';  /* backslash */
            cmd_string[pos++] = '\'';  /* the literal single-quote */
            cmd_string[pos++] = '\'';  /* reopen single-quoted string */
        } else {
            if (pos + 1 + 1 > cmd_len) { cmd_string[0] = '\0'; return -1; }
            cmd_string[pos++] = c;
        }
    }

    /* append closing quote */
    size_t slen = strlen(suffix);
    if (pos + slen + 1 > cmd_len) { cmd_string[0] = '\0'; return -1; }
    memcpy(cmd_string + pos, suffix, slen);
    pos += slen;

    cmd_string[pos] = '\0';
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
