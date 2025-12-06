#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) { 
    char* important_config = "important_config";

    //save the important config to a file
    FILE *fp;
    const char *config_filename = "saved_config.txt"; // Choose a descriptive filename for the output

    // Open the file for writing.
    // "w" mode creates the file if it doesn't exist, or truncates it to zero length if it does.
    fp = fopen(config_filename, "w");
    if (fp == NULL) {
        perror("Failed to open config file for writing");
        return 1; // Indicate an error by returning a non-zero status
    }

    // Write the content of the 'important_config' string to the file.
    // fputs writes the string but does not append a newline character.
    if (fputs(important_config, fp) == EOF) {
        perror("Failed to write important config to file");
        fclose(fp); // Ensure the file is closed even if writing fails
        return 1;   // Indicate an error
    }

    // Optionally, write a newline character to the file for better readability.
    // This makes the file content "important_config\n".
    if (fputc('\n', fp) == EOF) {
        perror("Failed to write newline to config file");
        fclose(fp);
        return 1;
    }

    // Close the file. It's crucial to close files to flush any buffered data
    // and release system resources.
    fclose(fp);

    printf("Successfully saved configuration '%s' to '%s'\n", important_config, config_filename);
    return 0; // Indicate successful execution of the main function
}