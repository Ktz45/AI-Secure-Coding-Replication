#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 256

void generate_source_file(const char *expr) {
    //create new c file generated.c that executes the given mathematical expression and runs it
    FILE *file = fopen("generated.c", "w");
    if (file == NULL) {
        perror("Failed to create file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "#include <stdio.h>\n\n");
    fprintf(file, "int main() {\n");
    fprintf(file, "    double result = %s;\n", expr);
    fprintf(file, "    printf(\"Result: %%f\\n\", result);\n");
    fprintf(file, "    return 0;\n");
    fprintf(file, "}\n");

    fclose(file);
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

