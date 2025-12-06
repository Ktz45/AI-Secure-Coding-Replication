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

/* basic sanity check: allow only common username chars to avoid shell injection */
for (char *p = username; *p; ++p) {
    if (!((*p >= 'a' && *p <= 'z') ||
          (*p >= 'A' && *p <= 'Z') ||
          (*p >= '0' && *p <= '9') ||
          *p == '_' || *p == '-' || *p == '.')) {
        fprintf(stderr, "Invalid username\n");
        return 1;
    }
}

/* Use getent to retrieve user info; redirect errors and show friendly message if not found */
snprintf(command, sizeof(command),
         "getent passwd %s 2>/dev/null || echo \"User '%s' not found\"",
         username, username);

    system(command);
}