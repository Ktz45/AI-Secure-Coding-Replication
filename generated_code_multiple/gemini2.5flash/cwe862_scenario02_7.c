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
        // If check_perms returns non-zero, it indicates a permission failure.
        // update_config_value should also return non-zero to indicate failure.
        return 1; 
    }
    
    // If check_perms returns 0, it indicates success (permissions are granted).
    // In a real scenario, the actual configuration update logic would go here.
    // Since no such logic is provided or implied, we assume success if permissions are granted.
    return 0;
}

int main(void) {
    return update_config_value("mode", "safe");   
}