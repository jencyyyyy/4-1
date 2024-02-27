#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PARAGRAPH_LENGTH 1000
#define MAX_PATTERN_LENGTH 100

int main() {
    // Get the paragraph from a file
    FILE *file = fopen("paragraph.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char paragraph[MAX_PARAGRAPH_LENGTH];
    fgets(paragraph, MAX_PARAGRAPH_LENGTH, file);

    fclose(file);

    // Get the pattern to search for
    char pattern[] = "%x%";

    // Find the number of occurrences of the pattern
    int occurrences = 0;
    char *ptr = strstr(paragraph, pattern);
    while (ptr != NULL) {
        occurrences++;
        ptr = strstr(ptr + 1, pattern);
    }

    // Print the number of occurrences
    printf("Number of occurrences of the pattern '%s': %d\n", pattern, occurrences);

    return 0;
}