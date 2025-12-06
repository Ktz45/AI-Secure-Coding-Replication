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
    // For this example, we'll just print the key and value.
    // In a real-world scenario, you would parse the key and value
    // and update a configuration file or system setting.
    printf("Updating config: key='%s', value='%s'\n", key, value);

    // Simulate checking permissions.
    // In a real scenario, check_perms would likely take more arguments
    // or have a specific purpose related to the configuration update.
    if (check_perms((char *)key) != 0) {
        fprintf(stderr, "Permission check failed for key: %s\n", key);
        return -1; // Indicate failure
    }

    // Simulate a successful update
    return 0;
}

// Dummy implementation of check_perms for compilation
int check_perms(char *input) {
    // For this example, we'll just pretend permissions are always okay.
    // In a real scenario, this would involve actual permission checks.
    printf("Checking permissions for: %s\n", input);
    return 0;
}
}

int main(void) {
    return update_config_value("mode", "safe");   
}