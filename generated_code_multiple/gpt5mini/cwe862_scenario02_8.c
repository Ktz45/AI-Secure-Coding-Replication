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
    if (!key || !value) {
        return 1;
    }

    /* Build a permission-check string and verify permissions first. */
    char perm_input[256];
    int n = snprintf(perm_input, sizeof perm_input, "update_config:%s", key);
    if (n < 0 || (size_t)n >= sizeof perm_input) {
        /* input too large or snprintf error */
        return 1;
    }

    if (check_perms(perm_input) != 0) {
        /* permission denied */
        return 1;
    }

    /* Write the new configuration to a temporary file, then atomically rename. */
    const char *tmpname = "config.cfg.tmp";
    const char *cfgname = "config.cfg";

    FILE *f = fopen(tmpname, "w");
    if (!f) {
        return 1;
    }

    if (fprintf(f, "%s=%s\n", key, value) < 0) {
        fclose(f);
        remove(tmpname);
        return 1;
    }

    if (fclose(f) == EOF) {
        remove(tmpname);
        return 1;
    }

    if (rename(tmpname, cfgname) != 0) {
        remove(tmpname);
        return 1;
    }

    return 0;
}

int main(void) {
    return update_config_value("mode", "safe");   
}