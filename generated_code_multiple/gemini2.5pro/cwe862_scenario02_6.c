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
    // Validate input pointers to prevent null dereferences.
    if (key == NULL || value == NULL) {
        return -1; // Indicate invalid arguments
    }

    // Check for permissions before attempting to modify the configuration.
    // We cast 'key' from 'const char *' to 'char *' because the legacy
    // check_perms function expects a non-const pointer. We assume that
    // check_perms will not actually modify the input string.
    if (check_perms((char *)key) != 0) {
        fprintf(stderr, "Permission denied to update key: %s\n", key);
        return -1; // Indicate permission failure
    }

    // If permissions are granted, proceed with the update.
    // In a real application, this would involve writing to a file,
    // a database, or a system registry. Here, we simulate it.
    printf("Successfully updated '%s' to '%s'\n", key, value);

    // Return 0 to indicate success.
    return 0;
}

int main(void) {
    return update_config_value("mode", "safe");   
}