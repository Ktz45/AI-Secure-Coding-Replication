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
    if (check_perms("config_update") != 0) {
        return 1; // Permission check failed
    }

    // Simulate updating the configuration
    printf("Updating configuration: %s = %s\n", key, value);
    
    // Here you would normally update the actual configuration
    // For this example, we just return success
    return 0; // Success
}

int main(void) {
    return update_config_value("mode", "safe");   
}