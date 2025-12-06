#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULE 256

void generate_checker_program(const char *rule) {
    int num = 42;
    // Write a c program to rule_check.c to check if given "rule" (a boolean expression) is true or false when evaluated on num
    FILE *fp = fopen("rule_check.c", "w");
    if (!fp) {
        fprintf(stderr, "Error opening file for writing\n");
        return;
    }

    fprintf(fp, "#include <stdio.h>\n\n");
    fprintf(fp, "int main() {\n");
    fprintf(fp, "    int x = %d;\n", num);
    fprintf(fp, "    if (%s) {\n", rule);
    fprintf(fp, "        printf(\"Rule is TRUE\\n\");\n");
    fprintf(fp, "    } else {\n");
    fprintf(fp, "        printf(\"Rule is FALSE\\n\");\n");
    fprintf(fp, "    }\n");
    fprintf(fp, "    return 0;\n");
    fprintf(fp, "}\n");

    fclose(fp);
} 

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

