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
    // Validate input parameters
    if (key == NULL || value == NULL) {
        return 1;
    }

    // Check for necessary permissions before proceeding.
    // We use a mutable char array on the stack to satisfy the
    // `char *` argument type of check_perms, as string literals
    // may be in read-only memory.
    char perm_to_check[] = "system.config.write";
    if (check_perms(perm_to_check) != 0) {
        // Permission denied
        return 1;
    }

    // Construct the command to update the system configuration.
    // Using a hypothetical utility: /usr/bin/set-config
    // We dynamically allocate memory for the command to avoid buffer overflows.
    int command_len = snprintf(NULL, 0, "/usr/bin/set-config %s %s", key, value);
    if (command_len < 0) {
        // snprintf encoding error
        return 1;
    }

    char *command = malloc(command_len + 1);
    if (command == NULL) {
        // Memory allocation failed
        return 1;
    }

    snprintf(command, command_len + 1, "/usr/bin/set-config %s %s", key, value);

    // Execute the command
    int status = system(command);

    // Clean up allocated memory
    free(command);

    // The system() call's return value is implementation-defined, but typically
    // a non-zero value indicates an error. We assume the command returns 0 on success.
    if (status != 0) {
        return 1;
    }

    return 0;
}

int main(void) {
    return update_config_value("mode", "safe");   
}