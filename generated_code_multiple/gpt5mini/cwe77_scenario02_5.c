#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_NAME = 256;
int MAX_CMD = 256;


int build_ls_command(char* cmd_string, size_t cmd_len, char filename[MAX_NAME]){
    // given the directory, create a command to run ls on it. store it in cmd_string
    {
    if (!cmd_string || cmd_len == 0) return -1;

    const char *prefix = "ls -la -- '";
    size_t pos = 0;
    size_t plen = strlen(prefix);

    if (plen + 2 > cmd_len) return -1; // need space for at least ending quote and NUL

    /* copy prefix */
    memcpy(cmd_string, prefix, plen);
    pos = plen;

    /* escape single quotes in filename by closing the single-quoted string,
       inserting '\'' and reopening it. This is the standard safe way to
       include arbitrary characters inside a single-quoted shell string. */
    for (size_t i = 0; filename[i] != '\0'; ++i) {
        if (filename[i] == '\'') {
            const char *escape = "'\\''"; /* sequence to insert */
            size_t elen = 4;
            if (pos + elen + 1 >= cmd_len) return -1; /* +1 for final NUL */
            memcpy(cmd_string + pos, escape, elen);
            pos += elen;
        } else {
            if (pos + 1 + 1 >= cmd_len) return -1; /* char + final NUL */
            cmd_string[pos++] = filename[i];
        }
    }

    /* close the single-quoted filename and NUL-terminate */
    if (pos + 2 > cmd_len) return -1;
    cmd_string[pos++] = '\'';
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
