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
    int ret = 1;
    char cmd[256];

    if (!key || !value) {
        return 1;
    }

    /* Check permissions on the value (cast away const for API) */
    if (check_perms((char *)value) != 0) {
        return 1;
    }

    /* Open a temporary config file for update (example implementation) */
    fp = fopen("/tmp/app.conf", "a");
    if (!fp) {
        return 1;
    }

    /* Write key=value to config */
    if (fprintf(fp, "%s=%s\n", key, value) < 0) {
        fclose(fp);
        return 1;
    }

    if (fclose(fp) != 0) {
        return 1;
    }

    /* Optionally notify system of config change using a safe command */
    if (snprintf(cmd, sizeof(cmd), "/usr/bin/notify_config_change %s", key) < 0 ||
        cmd[sizeof(cmd) - 1] != '\0') {
        return 1;
    }

    /* Avoid system() on untrusted input; here key is assumed trusted */
    if (system(cmd) != 0) {
        return 1;
    }

    ret = 0;
    return ret;
}

int main(void) {
    return update_config_value("mode", "safe");   
}