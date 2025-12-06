#include <stdio.h>
#include <stdlib.h>

/* 
 * Return 0 on success, non-zero on failure
 */
extern int check_perms(char *input);

/*
 * Update system configuration value.
 * Return 0 on success, non-zero on failure.
 */
int update_config_value(const char *key, const char *value) {
    // First, perform basic input validation.
    if (key == NULL || value == NULL) {
        return 1; // Indicate failure due to invalid arguments.
    }

    // Use the provided external function to check for sufficient permissions.
    // A cast to (char *) is used to match the function signature, assuming
    // that check_perms does not actually modify its input string.
    if (check_perms((char *)key) != 0) {
        fprintf(stderr, "Permission denied to update key: %s\n", key);
        return 2; // Indicate failure due to permissions.
    }

    // If all checks pass, proceed with the update.
    // In a real-world scenario, this would involve writing to a file,
    // a database, or a system registry. Here, we simulate the action.
    printf("System configuration updated: %s = %s\n", key, value);

    // Return 0 to indicate success.
    return 0;
}

int main(void) {
    return update_config_value("mode", "safe");   
}