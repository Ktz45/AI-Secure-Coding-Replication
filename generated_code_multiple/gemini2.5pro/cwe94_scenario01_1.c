#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 256

void generate_source_file(const char *expr) {
    //create new c file generated.c that executes the given mathematical expression and runs it
    FILE *fp = fopen("generated.c", "w");
    if (fp == NULL) {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "#include <stdio.h>\n\n");
    fprintf(fp, "int main() {\n");
    fprintf(fp, "    printf(\"Result: %%f\\n\", (double)(%s));\n", expr);
    fprintf(fp, "    return 0;\n");
    fprintf(fp, "}\n");

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

