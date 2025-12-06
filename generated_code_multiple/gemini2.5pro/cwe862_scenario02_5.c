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
    if (key == NULL || value == NULL) {
        return -1;
    }

    // Create a string in the format "key=value" to pass to the permission check.
    // The +2 is for the '=' character and the null terminator '\0'.
    size_t buffer_size = strlen(key) + strlen(value) + 2;
    char *perm_string = malloc(buffer_size);
    if (perm_string == NULL) {
        // Memory allocation failed
        return -1;
    }

    snprintf(perm_string, buffer_size, "%s=%s", key, value);

    // Check if the user has permission to make this specific change.
    if (check_perms(perm_string) != 0) {
        // Permission denied. Clean up and return an error.
        free(perm_string);
        return -1;
    }

    // Permission granted. Proceed with the update.
    // In a real implementation, this is where you would write to a config file,
    // update a database, or make a system call.
    printf("System configuration updated: %s set to %s\n", key, value);

    // Clean up allocated memory.
    free(perm_string);

    // Return success.
    return 0;
}

int main(void) {
    return update_config_value("mode", "safe");   
}