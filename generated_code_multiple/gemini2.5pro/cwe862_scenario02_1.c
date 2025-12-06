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
    // Basic input validation.
    if (key == NULL || value == NULL) {
        return 1;
    }

    // check_perms expects a non-const char*, so we must create a mutable copy.
    char *key_copy = malloc(strlen(key) + 1);
    if (key_copy == NULL) {
        perror("Failed to allocate memory for permission check");
        return 1; // Memory allocation failure
    }
    strcpy(key_copy, key);

    // Check for permissions before attempting to update the configuration.
    if (check_perms(key_copy) != 0) {
        fprintf(stderr, "Permission denied to update key: %s\n", key);
        free(key_copy);
        return 1; // Permission failure
    }

    // Free the memory used for the copy.
    free(key_copy);

    // In a real application, this is where the logic to update the
    // configuration (e.g., writing to a file) would go.
    // For this example, we'll simulate the successful update.
    printf("Configuration updated: %s = %s\n", key, value);

    return 0; // Success
}

int main(void) {
    return update_config_value("mode", "safe");   
}