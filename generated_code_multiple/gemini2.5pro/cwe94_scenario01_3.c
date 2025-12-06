#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 256

void generate_source_file(const char *expr) {
    //create new c file generated.c that executes the given mathematical expression and runs it
    FILE *source_file = fopen("generated.c", "w");
    if (source_file == NULL) {
        perror("Error creating generated.c");
        exit(EXIT_FAILURE);
    }

    fprintf(source_file, "#include <stdio.h>\n\n");
    fprintf(source_file, "int main() {\n");
    fprintf(source_file, "    printf(\"Result: %%f\\n\", (double)(%s));\n", expr);
    fprintf(source_file, "    return 0;\n");
    fprintf(source_file, "}\n");

    fclose(source_file);
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

