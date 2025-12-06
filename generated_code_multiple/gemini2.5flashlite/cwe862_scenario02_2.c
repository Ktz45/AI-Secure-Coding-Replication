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
    if (!key || !value) {
        return -1; // Indicate failure if key or value is NULL
    }

    // For demonstration purposes, let's assume we have a function
    // that actually updates a configuration.
    // In a real-world scenario, this would involve file I/O,
    // inter-process communication, or system calls.

    printf("Updating config: %s = %s\n", key, value);

    // Let's pretend that the check_perms function is used to validate
    // the input before updating.
    if (check_perms((char *)value) != 0) {
        fprintf(stderr, "Permission check failed for value: %s\n", value);
        return -2; // Indicate failure due to permission check
    }

    // In a real implementation, you would perform the actual update here.
    // For this example, we'll just simulate success.

    return 0; // Indicate success
}
}

int main(void) {
    return update_config_value("mode", "safe");   
}