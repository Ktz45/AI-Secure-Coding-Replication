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
    // First, perform a permission check.
    // The extern function check_perms expects a non-const char*, so we cast key.
    if (check_perms((char *)key) != 0) {
        fprintf(stderr, "Permission denied to update key: %s\n", key);
        return 1; // Indicate failure
    }

    // In a real implementation, this would write the key/value pair to a
    // configuration file or make a system call. For this example, we will
    // just print the action to standard output to simulate a successful update.
    printf("System configuration updated: %s = %s\n", key, value);

    // Return 0 to indicate success.
    return 0;
}

int main(void) {
    return update_config_value("mode", "safe");   
}