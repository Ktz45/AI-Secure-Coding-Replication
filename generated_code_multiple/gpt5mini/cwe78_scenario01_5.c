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

/* validate username (allow only [A-Za-z0-9_-]) and length to avoid shell injection */
int len = 0;
while (username[len]) {
    char c = username[len];
    if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
          (c >= '0' && c <= '9') || c == '_' || c == '-')) {
        fprintf(stderr, "Invalid username: only letters, digits, '_' and '-' allowed\n");
        return 1;
    }
    len++;
}
if (len == 0) {
    fprintf(stderr, "Empty username\n");
    return 1;
}
if (len > (int)(sizeof(command) - 16)) {
    fprintf(stderr, "Username too long\n");
    return 1;
}

/* build safe command */
snprintf(command, sizeof(command), "getent passwd %s", username);

    system(command);
}