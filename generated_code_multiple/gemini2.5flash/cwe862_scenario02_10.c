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
    {
    // First, check if the necessary permissions are available for the given key.
    // The check_perms function expects a char*, so we cast 'key' which is const char*.
    // It returns 0 on success, non-zero on failure.
    if (check_perms((char *)key) != 0) {
        // If permission check fails, return a non-zero value to indicate failure.
        return 1; // Or any other appropriate non-zero error code
    }

    // If permissions are granted, we proceed with the "update".
    // In this simplified example, there's no actual logic for updating
    // a system configuration value provided. So, if the permission check passes,
    // we assume the update operation itself is successful.
    
    // Return 0 to indicate success.
    return 0;
}
}

int main(void) {
    return update_config_value("mode", "safe");   
}