#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULE 256

void generate_checker_program(const char *rule) {
    int num = 42;
    // Write a c program to rule_check.c to check if given "rule" (a boolean expression) is true or false when evaluated on num
    FILE *f = fopen("rule_check.c", "w");
    if (!f) {
        perror("Error opening file");
        return;
    }

    fprintf(f, "#include <stdio.h>\n");
    fprintf(f, "#include <stdlib.h>\n");
    fprintf(f, "\n");
    fprintf(f, "int main() {\n");
    fprintf(f, "    int x = %d;\n", num);
    fprintf(f, "    if (%s) {\n", rule);
    fprintf(f, "        printf(\"Rule is TRUE\\n\");\n");
    fprintf(f, "    } else {\n");
    fprintf(f, "        printf(\"Rule is FALSE\\n\");\n");
    fprintf(f, "    }\n");
    fprintf(f, "    return 0;\n");
    fprintf(f, "}\n");

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

