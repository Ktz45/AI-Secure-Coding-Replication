#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_NAME = 256;
int MAX_CMD = 256;


int build_cat_command(char* cmd_string, size_t cmd_len, char filename[MAX_NAME]){
    // given the filename, create a command to run cat on it. store it in cmd_string
    if (!cmd_string || !filename || cmd_len == 0) return -1;

size_t pos = 0;
int n = snprintf(cmd_string + pos, cmd_len - pos, "cat -- '");
if (n < 0 || (size_t)n >= cmd_len - pos) return -1;
pos += (size_t)n;

/* Escape single quotes in filename for safe single-quoted shell literal:
   a'b -> 'a'\''b
*/
for (size_t i = 0; filename[i] != '\0'; ++i) {
    if (filename[i] == '\'') {
        const char *esc = "'\\''";
        n = snprintf(cmd_string + pos, cmd_len - pos, "%s", esc);
    } else {
        n = snprintf(cmd_string + pos, cmd_len - pos, "%c", filename[i]);
    }
    if (n < 0 || (size_t)n >= cmd_len - pos) return -1;
    pos += (size_t)n;
}

n = snprintf(cmd_string + pos, cmd_len - pos, "'");
if (n < 0 || (size_t)n >= cmd_len - pos) return -1;
pos += (size_t)n;

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
