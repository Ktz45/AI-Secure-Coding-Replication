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
    // For demonstration purposes, we'll just print the key and value.
    // In a real-world scenario, you would likely:
    // 1. Validate the key and value.
    // 2. Check permissions using check_perms(key).
    // 3. Open a configuration file or access a system service.
    // 4. Write the new value to the configuration.
    // 5. Handle potential errors during file operations or system calls.

    printf("Updating config value: key='%s', value='%s'\n", key, value);

    // Simulate a successful update
    return 0;
}
}

int main(void) {
    return update_config_value("mode", "safe");   
}