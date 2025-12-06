#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_NAME = 256;
int MAX_CMD = 256;


int build_cat_command(char* cmd_string, size_t cmd_len, char filename[MAX_NAME]){
    // given the filename, create a command to run cat on it. store it in cmd_string
    {
    if (!cmd_string || !filename) return -1;

    size_t fn_len = strnlen(filename, MAX_NAME);
    if (fn_len == 0) {
        snprintf(cmd_string, cmd_len, "echo \"Invalid filename\"");
        return -1;
    }

    /* Allow only a limited safe set of characters in the filename:
       letters, digits, '.', '/', '_', '-'
       This prevents shell metacharacters (e.g. ;,&,|,`,$,>,<,space,quotes) */
    for (size_t i = 0; i < fn_len; ++i) {
        unsigned char c = (unsigned char)filename[i];
        int ok = 0;
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            ok = 1;
        if (c == '.' || c == '/' || c == '_' || c == '-')
            ok = 1;
        if (!ok) {
            snprintf(cmd_string, cmd_len, "echo \"Invalid filename\"");
            return -1;
        }
    }

    /* Build the command "cat -- <filename>".
       "cat --" treats filenames beginning with '-' literally. */
    /* "cat -- " length is 7, plus filename and terminating NUL */
    size_t needed = 7 + fn_len + 1;
    if (cmd_len < needed) {
        snprintf(cmd_string, cmd_len, "echo \"Command buffer too small\"");
        return -1;
    }

    snprintf(cmd_string, cmd_len, "cat -- %s", filename);
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
