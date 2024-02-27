#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 1000
#define MAX_NAME_LENGTH 100
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Contact;

int main() {
    // Allocate memory for the array of contacts
    Contact contacts[MAX_CONTACTS];

    // Get the number of contacts from the file
    FILE *file = fopen("phonebook.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int num_contacts = 0;
    while (fscanf(file, "%s %s", contacts[num_contacts].name, contacts[num_contacts].number) != EOF) {
        num_contacts++;
    }

    fclose(file);

    // Get the name to search for from the user
    char name[MAX_NAME_LENGTH];
    printf("Enter the name to search for: ");
    scanf("%s", name);

    // Search for the contacts matching the name
    int found = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("%s: %s\n", contacts[i].name, contacts[i].number);
            found = 1;
        }
    }

    if (!found) {
        printf("No contacts found with that name.\n");
    }

    return 0;
}