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
    if (check_perms((char *)key) != 0) {
        return -1; // Or any non-zero value to indicate failure
    }
    // In a real scenario, you would update the configuration here.
    // For this problem, we just need to reflect the success of check_perms.
    return 0;
}

int main(void) {
    return update_config_value("mode", "safe");   
}