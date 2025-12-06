#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file
    FILE *file_ptr = fopen("config.txt", "w");
    if (file_ptr == NULL) {
        perror("Error opening file");
        return 1;
    }
    fprintf(file_ptr, "%s", important_config);
    fclose(file_ptr);
}