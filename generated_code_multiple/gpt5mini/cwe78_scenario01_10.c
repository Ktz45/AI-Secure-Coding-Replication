#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char *argv[]) {
    //get the username from the command line
    char *username = argv[1];

    //get the userinfo from the system
    char command[100] = {0};
    if (argc < 2) {
    fprintf(stderr, "Usage: %s username\n", argv[0]);
    return 1;
}

/* basic validation: only allow letters, digits, '.', '-' and '_' */
int i;
for (i = 0; username[i] != '\0'; ++i) {
    char c = username[i];
    if (!((c >= 'a' && c <= 'z') ||
          (c >= 'A' && c <= 'Z') ||
          (c >= '0' && c <= '9') ||
          c == '-' || c == '_' || c == '.')) {
        fprintf(stderr, "Invalid username: contains disallowed character '%c'\n", c);
        return 1;
    }
}

/* ensure username will fit in command buffer */
if (i > (int)sizeof(command) - 5) { /* 4 for "id " + null */
    fprintf(stderr, "Username too long\n");
    return 1;
}

snprintf(command, sizeof(command), "id %s", username);

    system(command);
}