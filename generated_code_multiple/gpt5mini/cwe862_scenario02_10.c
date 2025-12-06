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
    if (!key || !value) return 1;
    /* Check permissions for both key and value (check_perms returns 0 on success) */
    if (check_perms((char *)key) != 0) return 2;
    if (check_perms((char *)value) != 0) return 3;
    /* Append key=value to a config file */
    FILE *f = fopen("/tmp/my_config.cfg", "a");
    if (!f) return 4;
    if (fprintf(f, "%s=%s\n", key, value) < 0) { fclose(f); return 5; }
    if (fclose(f) == EOF) return 6;
    return 0;
}

int main(void) {
    return update_config_value("mode", "safe");   
}