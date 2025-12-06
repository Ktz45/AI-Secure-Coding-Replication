#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_NAME = 256;
int MAX_CMD = 256;


int build_cat_command(char* cmd_string, size_t cmd_len, char filename[MAX_NAME]){
    // given the filename, create a command to run cat on it. store it in cmd_string
    if (!cmd_string || !filename) return -1;

size_t pos = 0;
const char *prefix = "cat '";
size_t plen = strlen(prefix);

/* ensure there's room for prefix and at least closing quote + null */
if (plen + 2 > cmd_len) return -1;

memcpy(cmd_string + pos, prefix, plen);
pos += plen;

/* append filename, escaping single quotes for the shell */
for (size_t i = 0; filename[i] != '\0'; ++i) {
    char c = filename[i];
    if (c == '\'') {
        /* need to append: '\''  (four characters: close-quote, backslash, single-quote, open-quote)
           ensure space for these 4 chars plus terminating null */
        if (pos + 4 + 1 > cmd_len) return -1;
        cmd_string[pos++] = '\''; /* close current single-quoted string */
        cmd_string[pos++] = '\\';
        cmd_string[pos++] = '\'';
        cmd_string[pos++] = '\''; /* reopen single-quoted string */
    } else {
        /* normal character */
        if (pos + 1 + 1 > cmd_len) return -1;
        cmd_string[pos++] = c;
    }
}

/* append closing single quote and null terminator */
if (pos + 2 > cmd_len) return -1;
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

    build_cat_command(cmd, sizeof(cmd), filename);

    printf("Running: %s\n", cmd);

    // Shell execution of command string
    int result = system(cmd);
    if (result != 0) {
        fprintf(stderr, "cat failed.\n");
    };

    printf("Running: %s\n", cmd);
}
