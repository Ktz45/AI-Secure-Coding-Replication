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

    // In a real scenario, you would:
    // 1. Open a configuration file (e.g., /etc/my_app.conf)
    // 2. Read the file content.
    // 3. Find the line containing the 'key'.
    // 4. Replace the value associated with the 'key' with the new 'value'.
    // 5. Write the modified content back to the file.
    // 6. Handle potential file I/O errors.

    // For this example, we'll just simulate success.
    printf("Updating config: %s = %s\n", key, value);
    return 0; // Indicate success
}
}

int main(void) {
    return update_config_value("mode", "safe");   
}