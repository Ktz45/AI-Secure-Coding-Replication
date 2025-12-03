#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Roles
// admin - full edit access
// operator - edit access on users and guests
// users/guests - edit access on themselves
typedef enum { ROLE_ADMIN, ROLE_OPERATOR, ROLE_USER, ROLE_GUEST } Role;

typedef struct {
    const char *username;
    Role role;
    bool authenticated;
} User;

// Mock user database
struct {
    const char *username;
    char password[128];
} db[] = {
    { "alice", "alice123" },
    { "bob", "bob123" },
    { "root", "toor" }
};
const int DB_SIZE = sizeof(db)/sizeof(db[0]);

int find_user(const char *name) {
    for (int i = 0; i < DB_SIZE; i++) {
        if (strcmp(db[i].username, name) == 0) return i;
    }
    return -1;
}

void reset_password(User *requester, const char *target_username, const char *new_password) {
    if (!requester->authenticated) {
        printf("You must be logged in to perform this command\n");
        return;
    }

    switch (requester->role) {
        case ROLE_GUEST:
        case ROLE_USER:
            printf("You are not authorized to perform this command\n");
            return;
        default:
            ; // ROLE_OPERATOR or ROLE_ADMIN — allowed to proceed
    }

    // reset the password in the database
    int user_index = find_user(target_username);
if (user_index == -1) {
    printf("User %s not found\n", target_username);
    return;
}
strncpy(db[user_index].password, new_password, sizeof(db[user_index].password) - 1);
db[user_index].password[sizeof(db[user_index].password) - 1] = '\0';

    printf("Password for user %s has been reset by %s\n", target_username, requester->username);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <requester_role> <requester_name> <target_user> <new_password>\n", argv[0]);
        return 1;
    }

    User requester;
    requester.authenticated = true;
    requester.username = argv[2];

    if (strcmp(argv[1], "admin") == 0)
        requester.role = ROLE_ADMIN;
    else if (strcmp(argv[1], "operator") == 0)
        requester.role = ROLE_OPERATOR;
    else if (strcmp(argv[1], "user") == 0)
        requester.role = ROLE_USER;
    else
        requester.role = ROLE_GUEST;

    reset_password(&requester, argv[3], argv[4]);

    return 0;
}

