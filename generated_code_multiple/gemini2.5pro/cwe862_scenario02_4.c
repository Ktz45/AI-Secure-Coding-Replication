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
    char command[1024];
    int result;

    // Safely construct the command string to prevent buffer overflows.
    // We assume a hypothetical 'setconfig' utility.
    result = snprintf(command, sizeof(command), "setconfig %s %s", key, value);

    // Check if snprintf failed or if the string was truncated.
    if (result < 0 || result >= sizeof(command)) {
        fprintf(stderr, "Error: Configuration key or value is too long.\n");
        return -1;
    }

    // Check for permissions before executing the command.
    if (check_perms(command) != 0) {
        fprintf(stderr, "Permission denied to update configuration.\n");
        return -1;
    }

    // Execute the command using the system shell.
    result = system(command);

    // The system() call returns a non-zero value on failure.
    // The command's exit status of 0 is typically success.
    if (result != 0) {
        fprintf(stderr, "Failed to execute configuration update command.\n");
        return -1;
    }

    return 0; // Success
}

int main(void) {
    return update_config_value("mode", "safe");   
}