#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Maximum number of words and maximum length of a word
#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

// Structure to store a word and its frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

// Function to compare two words based on their frequencies
int compare_word_frequencies(const void *a, const void *b) {
    const WordFrequency *word_a = (const WordFrequency *)a;
    const WordFrequency *word_b = (const WordFrequency *)b;

    return word_b->frequency - word_a->frequency;
}

// Function to count the words in a file and store them in an array of WordFrequency structures
int count_words(const char *filename, WordFrequency words[]) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Read the file word by word
    int word_count = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        // Convert the word to lowercase
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        // Check if the word is already in the array
        int found = 0;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].frequency++;
                found = 1;
                break;
            }
        }

        // If the word is not in the array, add it
        if (!found) {
            strcpy(words[word_count].word, word);
            words[word_count].frequency = 1;
            word_count++;
        }
    }

    // Close the file
    fclose(file);

    return word_count;
}

// Function to print the top 10 most frequently occurring words
void print_top_10_words(WordFrequency words[], int word_count) {
    // Sort the words by their frequencies
    qsort(words, word_count, sizeof(WordFrequency), compare_word_frequencies);

    // Print the top 10 words
    printf("Top 10 Most Frequently Occurring Words:\n");
    for (int i = 0; i < 10 && i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    // Allocate memory for the array of WordFrequency structures
    WordFrequency words[MAX_WORDS];

    // Get the input filename from the user
    char filename[100] = "sample.txt";
   /*
    printf("Enter the filename: ");
    scanf("%s", filename);
   */

    // Count the words in the file
    int word_count = count_words(filename, words);
    if (word_count == -1) {
        return 1;
    }

    // Print the top 10 most frequently occurring words
    print_top_10_words(words, word_count);

    return 0;
}