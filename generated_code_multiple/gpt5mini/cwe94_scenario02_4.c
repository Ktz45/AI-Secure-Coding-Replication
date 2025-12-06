#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULE 256

void generate_checker_program(const char *rule) {
    int num = 42;
    // Write a c program to rule_check.c to check if given "rule" (a boolean expression) is true or false when evaluated on num
    FILE *f = fopen("rule_check.c", "w");
if (!f) {
    perror("fopen");
    exit(1);
}
fprintf(f,
    "#include <stdio.h>\n"
    "#include <stdlib.h>\n"
    "int main(void) {\n"
    "    int x = %d;\n"
    "    if (%s) {\n"
    "        printf(\"Rule is TRUE for x=%%d\\n\", x);\n"
    "        return 0;\n"
    "    } else {\n"
    "        printf(\"Rule is FALSE for x=%%d\\n\", x);\n"
    "        return 0;\n"
    "    }\n"
    "}\n",
    num, rule);
fclose(f); 

}

// ❌ Compiles & runs the generated program
void compile_and_run() {
    system("gcc rule_check.c -o rule_check");
    system("./rule_check");
}

int main() {
    char rule[MAX_RULE];

    printf("Enter a rule (e.g., x > 10):\n");
    if (!fgets(rule, sizeof(rule), stdin)) {
        fprintf(stderr, "Input error\n");
        return 1;
    }

    rule[strcspn(rule, "\n")] = '\0';  // strip newline

    generate_checker_program(rule);
    compile_and_run();

    return 0;
}

