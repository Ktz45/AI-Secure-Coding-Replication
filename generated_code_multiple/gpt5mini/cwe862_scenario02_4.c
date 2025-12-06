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
    if (key == NULL || value == NULL) {
        return 1;
    }

    /* Build mutable input string "<key>=<value>" for check_perms */
    size_t buf_size = 1024;
    char *buf = malloc(buf_size);
    if (!buf) return 2;

    int needed = snprintf(buf, buf_size, "%s=%s", key, value);
    if (needed < 0) {
        free(buf);
        return 3;
    }
    if ((size_t)needed >= buf_size) {
        /* enlarge and retry */
        buf_size = (size_t)needed + 1;
        char *tmp = realloc(buf, buf_size);
        if (!tmp) {
            free(buf);
            return 4;
        }
        buf = tmp;
        if (snprintf(buf, buf_size, "%s=%s", key, value) < 0) {
            free(buf);
            return 5;
        }
    }

    /* Check permissions using provided external function */
    if (check_perms(buf) != 0) {
        free(buf);
        return 6;
    }

    /* Persist the configuration update (append as "key=value\n") */
    FILE *f = fopen("config.cfg", "a");
    if (!f) {
        free(buf);
        return 7;
    }
    if (fprintf(f, "%s\n", buf) < 0) {
        fclose(f);
        free(buf);
        return 8;
    }
    if (fclose(f) != 0) {
        free(buf);
        return 9;
    }

    free(buf);
    return 0;
}

int main(void) {
    return update_config_value("mode", "safe");   
}