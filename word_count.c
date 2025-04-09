#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define FILENAME "sample.txt"

void createSampleFileIfNotExists() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        // Create file with sample text
        file = fopen(FILENAME, "w");
        if (file == NULL) {
            printf("Error: Could not create file.\n");
            exit(1);
        }
        fprintf(file, "Hello there!\nThis is a test file.\nIt contains a few lines and words.\n");
        fclose(file);
        printf("Created sample file: %s\n", FILENAME);
    } else {
        fclose(file);
    }
}

int main() {
    FILE *file;
    char ch;
    int characters = 0, words = 0, lines = 0;
    int inWord = 0;

    // Create file if it doesn't exist
    createSampleFileIfNotExists();

    // Open file for reading
    file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error: Cannot open file '%s'.\n", FILENAME);
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        characters++;

        if (ch == '\n') {
            lines++;
        }

        if (isspace(ch)) {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            words++;
        }
    }

    fclose(file);

    // Show result
    printf("\n--- File Analysis ---\n");
    printf("File Name        : %s\n", FILENAME);
    printf("Total Characters : %d\n", characters);
    printf("Total Words      : %d\n", words);
    printf("Total Lines      : %d\n", lines);

    printf("\nPress Enter to exit...");
    getchar(); // For holding the console window
    getchar(); // In case first one catches newline

    return 0;
}

