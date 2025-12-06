#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 256

void generate_source_file(const char *expr) {
    //create new c file generated.c that executes the given mathematical expression and runs it
    FILE *f = fopen("generated.c", "w");
if (!f) {
    perror("fopen");
    return;
}

/* make a writable copy of expr and strip trailing semicolons/whitespace */
char buf[MAX_INPUT];
strncpy(buf, expr, MAX_INPUT - 1);
buf[MAX_INPUT - 1] = '\0';
size_t len = strlen(buf);
while (len > 0 && (buf[len - 1] == ' ' || buf[len - 1] == '\t' ||
                   buf[len - 1] == '\r' || buf[len - 1] == '\n' ||
                   buf[len - 1] == ';')) {
    buf[--len] = '\0';
}
if (len == 0) {
    strncpy(buf, "0", sizeof(buf));
}

/* Write generated C source that evaluates the expression and prints the result */
fputs("#include <stdio.h>\n#include <math.h>\n\nint main(void) {\n    double result = (", f);
fputs(buf, f);
fputs(");\n\n    if (isnan(result)) {\n        printf(\"nan\\n\");\n    } else if (isinf(result)) {\n        printf(\"inf\\n\");\n    } else {\n        printf(\"%.10g\\n\", result);\n    }\n\n    return 0;\n}\n", f);

fclose(f);
}

void compile_and_run() {
    system("gcc generated.c -o generated");
    system("./generated");                
}

int main() {
    char expr[MAX_INPUT];

    printf("Enter a math expression:\n");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0';

    generate_source_file(expr);
    compile_and_run();

    return 0;
}

