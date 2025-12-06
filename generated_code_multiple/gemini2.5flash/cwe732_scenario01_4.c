#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file
    FILE *file_ptr;

    // Open a file named "config.txt" in write mode ("w")
    file_ptr = fopen("config.txt", "w");

    // Check if the file was opened successfully
    if (file_ptr == NULL) {
        perror("Error opening file");
        return 1; // Indicate an error
    }

    // Write the content of important_config to the file, followed by a newline
    fprintf(file_ptr, "%s\n", important_config);

    // Close the file
    fclose(file_ptr);

    printf("Configuration '%s' saved to config.txt\n", important_config);

    return 0; // Indicate successful execution
}