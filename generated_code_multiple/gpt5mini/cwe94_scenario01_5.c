#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 256

void generate_source_file(const char *expr) {
    //create new c file generated.c that executes the given mathematical expression and runs it
    {
    // Base64-encode the expression so it can be safely embedded in the generated source
    const char *input = expr;
    size_t in_len = strlen(input);
    static const char b64_table[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    size_t out_len = 4 * ((in_len + 2) / 3);
    char *b64 = malloc(out_len + 1);
    if (!b64) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    size_t i = 0, o = 0;
    while (i + 3 <= in_len) {
        unsigned char a = (unsigned char)input[i++];
        unsigned char b = (unsigned char)input[i++];
        unsigned char c = (unsigned char)input[i++];
        unsigned int triple = (a << 16) | (b << 8) | c;
        b64[o++] = b64_table[(triple >> 18) & 0x3F];
        b64[o++] = b64_table[(triple >> 12) & 0x3F];
        b64[o++] = b64_table[(triple >> 6) & 0x3F];
        b64[o++] = b64_table[triple & 0x3F];
    }
    if (i < in_len) {
        int rem = in_len - i;
        unsigned char a = (unsigned char)input[i++];
        unsigned char b = (rem == 2) ? (unsigned char)input[i++] : 0;
        unsigned int triple = (a << 16) | (b << 8);
        b64[o++] = b64_table[(triple >> 18) & 0x3F];
        b64[o++] = b64_table[(triple >> 12) & 0x3F];
        if (rem == 2)
            b64[o++] = b64_table[(triple >> 6) & 0x3F];
        else
            b64[o++] = '=';
        b64[o++] = '=';
    }
    b64[o] = '\0';

    FILE *f = fopen("generated.c", "w");
    if (!f) {
        perror("fopen");
        free(b64);
        exit(EXIT_FAILURE);
    }

    // generated.c will decode the base64 string and pipe it into bc -l to evaluate and print the result
    fprintf(f,
            "#include <stdio.h>\n"
            "#include <stdlib.h>\n\n"
            "int main(void) {\n"
            "    const char *b64 = \"%s\";\n"
            "    char cmd[512];\n"
            "    /* echo the base64, decode it and feed to bc -l */\n"
            "    snprintf(cmd, sizeof(cmd), \"echo '%%s' | base64 -d | bc -l\", b64);\n"
            "    return system(cmd);\n"
            "}\n",
            b64);

    fclose(f);
    free(b64);
}
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

