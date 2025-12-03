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
    // string.h is needed for snprintf and strlen
    #include <string.h>

    // Validate input parameters
    if (key == NULL || value == NULL) {
        fprintf(stderr, "Error: key and value must not be NULL.\n");
        return -1;
    }

    // Check for permissions before proceeding
    if (check_perms((char *)key) != 0) {
        fprintf(stderr, "Permission denied for key '%s'.\n", key);
        return -1;
    }

    // Construct the command to update the configuration.
    // We assume a command-line utility "sys_config_set" exists.
    // Format: sys_config_set <key> "<value>"
    // Using snprintf to safely construct the command string.
    // First, calculate the required size.
    int size = snprintf(NULL, 0, "sys_config_set %s \"%s\"", key, value);
    if (size < 0) {
        fprintf(stderr, "Error: snprintf encoding error.\n");
        return -1;
    }

    // Allocate memory for the command string (+1 for null terminator)
    char *command = malloc(size + 1);
    if (command == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for command.\n");
        return -1;
    }

    // Populate the command string
    snprintf(command, size + 1, "sys_config_set %s \"%s\"", key, value);

    // Execute the command using the system() call
    int status = system(command);

    // Free the allocated memory
    free(command);

    // system() returns 0 on success for the executed command's exit status
    if (status != 0) {
        fprintf(stderr, "Error: Failed to execute update for key '%s'.\n", key);
        return -1;
    }

    return 0; // Success
}

int main(void) {
    return update_config_value("mode", "safe");   
}