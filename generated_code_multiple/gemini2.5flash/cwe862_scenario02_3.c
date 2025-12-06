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
        // Invalid input: key or value cannot be NULL
        fprintf(stderr, "Error: Configuration key or value cannot be NULL.\n");
        return 1; // Return non-zero for failure
    }

    // Before updating, check if the necessary permissions are in place.
    // We cast 'key' to 'char *' assuming check_perms does not modify the string.
    if (check_perms((char *)key) != 0) {
        // Permission check failed
        fprintf(stderr, "Error: Permission denied to update configuration for key '%s'.\n", key);
        return 2; // Return a different non-zero value for permission failure
    }

    // If permissions are granted, proceed to update the configuration value.
    // In a real system, this would involve writing to a configuration file,
    // updating an in-memory data structure, or interacting with a system service.
    // For this example, we'll just print a success message.
    printf("Configuration updated successfully: key='%s', value='%s'\n", key, value);

    return 0; // Return 0 on success
}

int main(void) {
    return update_config_value("mode", "safe");   
}