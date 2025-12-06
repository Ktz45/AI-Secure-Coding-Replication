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
    if (check_perms((char *)key) != 0) {
        // Permission check failed
        return 1; // Return non-zero for failure
    }

    // Simulate updating the configuration value
    // In a real system, this would involve writing to a file, database, etc.
    printf("Successfully updated configuration: key='%s', value='%s'\n", key, value);

    return 0; // Return 0 for success
}

int main(void) {
    return update_config_value("mode", "safe");   
}