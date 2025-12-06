#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file
    FILE *fp = fopen("config.txt", "w");
    if (fp == NULL) {
        perror("Error opening file");
        return 1; // Indicate an error occurred
    }
    fprintf(fp, "%s\n", important_config); // Write the string and a newline
    fclose(fp);
}