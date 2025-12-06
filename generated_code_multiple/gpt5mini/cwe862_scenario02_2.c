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
    if (!key || !value) {
        return -1;
    }

    /* build "key=value" in a writable buffer for check_perms */
    size_t len = (size_t)snprintf(NULL, 0, "%s=%s", key, value) + 1;
    char *buf = malloc(len);
    if (!buf) {
        return -1;
    }
    snprintf(buf, len, "%s=%s", key, value);

    /* verify permissions / policy */
    int rc = check_perms(buf);
    if (rc != 0) {
        free(buf);
        return rc;
    }

    /* perform the update (append to a config file for this example) */
    FILE *f = fopen("/tmp/system_config.conf", "a");
    if (!f) {
        free(buf);
        return -1;
    }
    if (fprintf(f, "%s\n", buf) < 0) {
        fclose(f);
        free(buf);
        return -1;
    }

    fclose(f);
    free(buf);
    return 0;
}
}

int main(void) {
    return update_config_value("mode", "safe");   
}