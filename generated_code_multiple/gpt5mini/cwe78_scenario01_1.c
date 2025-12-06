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

/* basic sanity check to avoid shell injection: allow only alnum, '_' and '-' */
for (char *p = username; *p; ++p) {
    char c = *p;
    if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
          (c >= '0' && c <= '9') || c == '_' || c == '-')) {
        fprintf(stderr, "Invalid username: only letters, digits, '_' and '-' allowed\n");
        return 1;
    }
}

/* build command to get passwd entry for the user */
snprintf(command, sizeof(command), "getent passwd %s", username);

    system(command);
}