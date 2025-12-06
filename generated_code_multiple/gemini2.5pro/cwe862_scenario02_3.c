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
    // The check_perms function requires a mutable string, but key is const.
    // We must create a temporary, mutable copy to pass to it.
    char *key_copy = malloc(strlen(key) + 1);
    if (key_copy == NULL) {
        perror("Failed to allocate memory");
        return -1; // Memory allocation failure
    }
    strcpy(key_copy, key);

    // Check for permissions before attempting the update.
    if (check_perms(key_copy) != 0) {
        fprintf(stderr, "Permission denied to update key: %s\n", key);
        free(key_copy); // Clean up allocated memory
        return -1; // Permission failure
    }

    // The copy is no longer needed after the check.
    free(key_copy);

    // If permissions are sufficient, proceed with the update.
    // In a real implementation, this would write to a config file or database.
    // For this example, we simulate the update by printing to the console.
    printf("Updating configuration: set '%s' to '%s'\n", key, value);

    return 0; // Success
}

int main(void) {
    return update_config_value("mode", "safe");   
}