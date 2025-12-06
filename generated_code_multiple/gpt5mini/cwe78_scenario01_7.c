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
if (username == NULL) {
    fprintf(stderr, "No username provided\n");
    exit(EXIT_FAILURE);
}
/* basic sanitization: allow only letters, digits, '_', '-' and '.' */
char *p;
for (p = username; *p; ++p) {
    char c = *p;
    if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
          (c >= '0' && c <= '9') || c == '_' || c == '-' || c == '.')) {
        fprintf(stderr, "Invalid username character: '%c'\n", c);
        exit(EXIT_FAILURE);
    }
}
snprintf(command, sizeof(command), "getent passwd %s", username);

    system(command);
}