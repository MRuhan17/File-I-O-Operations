#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char line[256];

    file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    int wordCount = 0, charCount = 0;
    while (fgets(line, sizeof(line), file)) {
        charCount += strlen(line);
        char *word = strtok(line, " ");
        while (word) {
            wordCount++;
            word = strtok(NULL, " ");
        }
    }
    fclose(file);

    printf("Total words: %d\n", wordCount);
    printf("Total characters: %d\n", charCount);
    return 0;
}
