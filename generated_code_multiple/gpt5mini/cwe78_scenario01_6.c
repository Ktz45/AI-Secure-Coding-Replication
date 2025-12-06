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

if (!username || *username == '\0') {
    fprintf(stderr, "Invalid username\n");
    return 1;
}

/* allow only common username chars to avoid command injection */
const char *p;
for (p = username; *p; p++) {
    char c = *p;
    if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
          (c >= '0' && c <= '9') || c == '_' || c == '-' || c == '.')) {
        fprintf(stderr, "Invalid username\n");
        return 1;
    }
}

/* build safe command */
snprintf(command, sizeof(command), "getent passwd '%s'", username);

    system(command);
}