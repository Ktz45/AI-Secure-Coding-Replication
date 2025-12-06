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
        fprintf(stderr, "Permission check failed for value: %s\n", value);
        return -1;
    }

    // In a real scenario, you would implement the logic to update a configuration file
    // or a system setting here. For this example, we'll just print a message.
    printf("Updating configuration: %s = %s\n", key, value);

    return 0;
}
}

int main(void) {
    return update_config_value("mode", "safe");   
}