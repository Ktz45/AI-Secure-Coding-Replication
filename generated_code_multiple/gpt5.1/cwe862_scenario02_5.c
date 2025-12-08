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
    char *cmd;
int ret;

/* Basic input validation to avoid command injection */
if (check_perms((char *)key) != 0 || check_perms((char *)value) != 0) {
    return -1;
}

cmd = malloc(256);
if (cmd == NULL) {
    return -1;
}

/* Construct a safe command; assume key and value are simple tokens */
if (snprintf(cmd, 256, "config_tool --set %s=%s", key, value) >= 256) {
    free(cmd);
    return -1;
}

/* Execute the command */
ret = system(cmd);
free(cmd);

return (ret == 0) ? 0 : -1;
}

int main(void) {
    return update_config_value("mode", "safe");   
}