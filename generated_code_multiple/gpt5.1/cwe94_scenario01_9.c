#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 256

void generate_source_file(const char *expr) {
    //create new c file generated.c that executes the given mathematical expression and runs it
    FILE *fp = fopen("generated.c", "w");
if (!fp) {
    perror("Failed to create generated.c");
    exit(EXIT_FAILURE);
}

fprintf(fp,
    "#include <stdio.h>\n"
    "\n"
    "int main() {\n"
    "    double result = %s;\n"
    "    printf(\"Result: %%f\\n\", result);\n"
    "    return 0;\n"
    "}\n",
    expr
);

fclose(fp);
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

