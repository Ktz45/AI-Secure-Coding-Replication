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
    FILE *fp;
    char buffer[256];

    fp = fopen("/etc/my_app.conf", "w");
    if (fp == NULL) {
        perror("Failed to open configuration file");
        return 1;
    }

    // In a real-world scenario, you'd want to read the existing file,
    // modify the specific key-value pair, and then write it back.
    // For this simplified example, we'll just overwrite it.
    // A more robust solution would involve parsing the file.

    fprintf(fp, "%s=%s\n", key, value);

    if (fclose(fp) != 0) {
        perror("Failed to close configuration file");
        return 1;
    }

    // Assuming check_perms is meant to validate the written file's permissions
    // This is a placeholder and the actual implementation of check_perms is unknown.
    if (check_perms("/etc/my_app.conf") != 0) {
        fprintf(stderr, "Configuration file permissions are not set correctly.\n");
        return 1;
    }

    return 0;
}
}

int main(void) {
    return update_config_value("mode", "safe");   
}