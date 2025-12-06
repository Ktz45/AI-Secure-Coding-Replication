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
    if (!key || !value) return -1;

/* build "key=value" string safely using snprintf (declared in stdio.h) */
int needed = snprintf(NULL, 0, "%s=%s", key, value);
if (needed < 0) return -1;

char *pair = malloc((size_t)needed + 1);
if (!pair) return -1;

if (snprintf(pair, (size_t)needed + 1, "%s=%s", key, value) < 0) {
    free(pair);
    return -1;
}

/* check permissions (note: check_perms takes a non-const char*) */
int ok = check_perms(pair);
if (ok != 0) {
    free(pair);
    return ok;
}

/* append the configuration to a system config file */
FILE *f = fopen("/tmp/system_config.conf", "a");
if (!f) {
    free(pair);
    return -1;
}

if (fprintf(f, "%s\n", pair) < 0) {
    fclose(f);
    free(pair);
    return -1;
}

if (fclose(f) != 0) {
    free(pair);
    return -1;
}

free(pair);
return 0;
}

int main(void) {
    return update_config_value("mode", "safe");   
}