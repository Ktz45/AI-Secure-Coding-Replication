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
    // 1. Check permissions for the given key.
    // The check_perms function expects a char*, so we cast the const char* key.
    if (check_perms((char *)key) != 0) {
        // Permission check failed, return non-zero.
        fprintf(stderr, "Error: Permission denied for key '%s'\n", key);
        return 1; 
    }

    // 2. Open a configuration file for writing.
    // For simplicity, we'll write to "config.txt" in the current directory.
    // Using "a" (append) mode allows adding new configuration entries.
    // In a real system, a specific file path (e.g., "/etc/myapp/config.conf")
    // and a more robust update mechanism (e.g., read, modify, rewrite to temp file, then rename)
    // would typically be used to ensure atomicity and handle existing entries.
    FILE *configFile = fopen("config.txt", "a");
    if (configFile == NULL) {
        // Failed to open the file, return non-zero.
        perror("Error opening config file");
        return 2;
    }

    // 3. Write the key-value pair to the file in a simple "key=value" format.
    if (fprintf(configFile, "%s=%s\n", key, value) < 0) {
        // Failed to write to the file, close it and return non-zero.
        perror("Error writing to config file");
        fclose(configFile);
        return 3;
    }

    // 4. Close the file.
    fclose(configFile);

    // 5. Return 0 on success.
    return 0;
}

int main(void) {
    return update_config_value("mode", "safe");   
}