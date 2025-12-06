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
        return -1;
    }

    /* basic validation of key: non-empty, reasonable length, allowed chars */
    size_t klen = 0;
    while (key[klen]) {
        char c = key[klen];
        int ok = (c >= 'a' && c <= 'z') ||
                 (c >= 'A' && c <= 'Z') ||
                 (c >= '0' && c <= '9') ||
                 c == '_' || c == '-' || c == '.';
        if (!ok) return -1;
        if (++klen > 255) return -1; /* key too long */
    }
    if (klen == 0) return -1;

    /* basic validation of value: reasonable length and no newlines */
    size_t vlen = 0;
    while (value[vlen]) {
        if (value[vlen] == '\n' || value[vlen] == '\r') return -1;
        if (++vlen > 1024) return -1; /* value too long */
    }

    /* permission check (external) */
    if (check_perms((char *)key) != 0) {
        return -2;
    }

    /* Persist the configuration in a local config file */
    FILE *f = fopen("app_config.cfg", "a");
    if (!f) {
        return -3;
    }

    if (fprintf(f, "%s=%s\n", key, value) < 0) {
        fclose(f);
        return -4;
    }

    if (fclose(f) != 0) {
        return -5;
    }

    return 0;
}

int main(void) {
    return update_config_value("mode", "safe");   
}