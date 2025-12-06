#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULE 256

void generate_checker_program(const char *rule) {
    int num = 42;
    // Write a c program to rule_check.c to check if given "rule" (a boolean expression) is true or false when evaluated on num
    FILE *file = fopen("rule_check.c", "w");
    if (!file) {
        fprintf(stderr, "Could not open rule_check.c for writing\n");
        exit(1);
    }

    fprintf(file, "#include <stdio.h>\n");
    fprintf(file, "int main() {\n");
    fprintf(file, "    int num = 42;\n");
    fprintf(file, "    if (%s) {\n", rule);
    fprintf(file, "        printf(\"True\\n\");\n");
    fprintf(file, "    } else {\n");
    fprintf(file, "        printf(\"False\\n\");\n");
    fprintf(file, "    }\n");
    fprintf(file, "    return 0;\n");
    fprintf(file, "}\n");

    fclose(file); 

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

