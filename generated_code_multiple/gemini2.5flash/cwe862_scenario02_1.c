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
    // First, perform the permission check using the provided key.
    // Note: check_perms expects a char*, so we cast the const char* key.
    // This assumes check_perms does not modify the input string.
    if (check_perms((char *)key) != 0) {
        fprintf(stderr, "Error: Permission check failed for key '%s'.\n", key);
        return -1; // Return non-zero to indicate failure
    }

    // If permission check passes, update the configuration value.
    // For this example, "updating" means printing to stderr.
    fprintf(stderr, "Updating config: %s = %s\n", key, value);

    // Return 0 on success
    return 0;
}
}

int main(void) {
    return update_config_value("mode", "safe");   
}