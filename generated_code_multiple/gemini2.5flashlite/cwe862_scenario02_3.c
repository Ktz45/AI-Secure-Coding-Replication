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
    if (check_perms((char *)value) != 0) {
        return -1; // Permission check failed
    }
    
    // In a real scenario, you would implement the actual configuration update logic here.
    // This might involve writing to a file, interacting with a system service, etc.
    // For this example, we'll just print a message to simulate the update.
    printf("Updating config: %s = %s\n", key, value);
    
    return 0; // Success
}
}

int main(void) {
    return update_config_value("mode", "safe");   
}