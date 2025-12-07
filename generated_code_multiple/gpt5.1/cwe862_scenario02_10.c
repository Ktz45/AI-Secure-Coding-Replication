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
    if (check_perms("update_config") != 0) {
        return -1;
    }

    if (key == NULL || value == NULL) {
        return -1;
    }

    FILE *f = fopen("/tmp/config.txt", "a");
    if (!f) {
        return -1;
    }

    if (fprintf(f, "%s=%s\n", key, value) < 0) {
        fclose(f);
        return -1;
    }

    fclose(f);
    return 0;
}

int main(void) {
    return update_config_value("mode", "safe");   
}