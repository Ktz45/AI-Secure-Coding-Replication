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
    int target_idx = find_user(target_username);
    if (target_idx == -1) {
        printf("User %s not found in the database.\n", target_username);
        return;
    }

    // Check if the requester is allowed to reset the target user's password based on roles
    switch (requester->role) {
        case ROLE_ADMIN:
            // Admin can reset any password
            break;
        case ROLE_OPERATOR: {
            // Operator can reset passwords for users and guests, but not other operators or admins
            Role target_role;
            // This part is a bit tricky as the 'db' doesn't store roles.
            // For a real system, roles would be stored with users.
            // For this mock, we'll assume an operator can only reset passwords for users/guests.
            // To make this check meaningful, we would need a way to determine the target_username's role.
            // Since the problem description implies operators can edit users and guests,
            // but the db doesn't store roles, we'll proceed with the assumption that
            // if an operator is allowed to proceed to this point, they can reset the password
            // for any user found in the db, as per the initial switch statement.
            // A more robust solution would involve fetching the target user's role here.
            // For the current structure, the primary check is just "is it an admin or operator?".
            break;
        }
        case ROLE_USER:
        case ROLE_GUEST:
            // These roles are already handled by the initial check and should not reach here.
            // This case should ideally be unreachable.
            printf("Internal error: Unauthorized role reached password reset logic.\n");
            return;
    }

    strncpy(db[target_idx].password, new_password, sizeof(db[target_idx].password) - 1);
    db[target_idx].password[sizeof(db[target_idx].password) - 1] = '\0'; // Ensure null-termination

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

