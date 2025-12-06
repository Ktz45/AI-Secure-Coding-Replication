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
    // check_perms requires a mutable string, so we must create a copy
    // of the key-value pair. We'll format it as "key=value".
    size_t key_len = strlen(key);
    size_t value_len = strlen(value);
    // Allocate buffer for key, '=', value, and the null terminator.
    char *buffer = malloc(key_len + value_len + 2);

    if (buffer == NULL) {
        // Memory allocation failed.
        return -1;
    }

    // Construct the string for the permission check.
    sprintf(buffer, "%s=%s", key, value);

    int result = check_perms(buffer);

    // Free the dynamically allocated memory.
    free(buffer);

    if (result != 0) {
        // Permission check failed.
        return -1;
    }

    // If permissions are okay, proceed with the actual update.
    // (This part is a placeholder for real implementation logic).
    // For example: write_to_config_file(key, value);

    // Return 0 on success.
    return 0;
}

int main(void) {
    return update_config_value("mode", "safe");   
}