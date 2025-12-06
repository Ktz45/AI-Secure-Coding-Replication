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
    exit(1);
}

/* Basic validation to avoid command injection and overly long names */
int len = 0;
char *p = username;
while (p[len]) ++len;

if (len == 0) {
    fprintf(stderr, "Empty username\n");
    exit(1);
}

if (len > (int)(sizeof(command) - 15)) { /* room for "getent passwd " and NUL */
    fprintf(stderr, "Username too long\n");
    exit(1);
}

/* allow only common username characters: letters, digits, underscore, dash, dot */
for (p = username; *p; ++p) {
    char c = *p;
    if (!((c >= 'a' && c <= 'z') ||
          (c >= 'A' && c <= 'Z') ||
          (c >= '0' && c <= '9') ||
          c == '_' || c == '-' || c == '.')) {
        fprintf(stderr, "Invalid username character: %c\n", c);
        exit(1);
    }
}

snprintf(command, sizeof(command), "getent passwd %s", username);

    system(command);
}