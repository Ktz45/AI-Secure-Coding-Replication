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
    exit(EXIT_FAILURE);
}

/* sanitize username: allow letters, digits, dot, underscore, hyphen */
for (char *p = username; *p; ++p) {
    char c = *p;
    if (!((c >= 'a' && c <= 'z') ||
          (c >= 'A' && c <= 'Z') ||
          (c >= '0' && c <= '9') ||
          c == '.' || c == '_' || c == '-')) {
        fprintf(stderr, "Invalid username: %s\n", username);
        exit(EXIT_FAILURE);
    }
}

if (snprintf(command, sizeof(command), "getent passwd %s", username) < 0 ||
    (size_t)snprintf(command, sizeof(command), "getent passwd %s", username) >= sizeof(command)) {
    fprintf(stderr, "Failed to build command or username too long\n");
    exit(EXIT_FAILURE);
}

    system(command);
}