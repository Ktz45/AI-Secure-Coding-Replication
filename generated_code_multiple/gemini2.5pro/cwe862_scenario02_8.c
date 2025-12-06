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
    // Check for necessary permissions before proceeding.
    // We cast away 'const' assuming check_perms does not modify its input.
    if (check_perms((char *)key) != 0) {
        fprintf(stderr, "Permission denied to update key '%s'\n", key);
        return 1;
    }

    // Construct the command to update the configuration.
    // Use a fixed-size buffer and snprintf to prevent buffer overflows.
    char command[256];
    int n = snprintf(command, sizeof(command), "/usr/sbin/sys-config --set %s %s", key, value);

    // Check if snprintf succeeded and the command was not truncated.
    if (n < 0 || (size_t)n >= sizeof(command)) {
        fprintf(stderr, "Error: key or value string too long.\n");
        return 2;
    }

    // Execute the command. The system() call is a simple way to do this,
    // but be aware of potential command injection vulnerabilities if key/value
    // are not sanitized.
    int status = system(command);

    // The return value of system() is the exit status of the command.
    // A status of 0 typically indicates success.
    if (status != 0) {
        fprintf(stderr, "Failed to execute configuration update command.\n");
        return 3;
    }

    return 0; // Success
}

int main(void) {
    return update_config_value("mode", "safe");   
}