#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size of the list

// Global variables
int list[MAX_SIZE]; // Array to store list elements
int count = 0;      // Current number of elements in the list

// Function prototypes
void insert(int number);
void delete(int number);
void display();
void menu();

int main() {
    menu();
    return 0;
}

// Function to display the menu and get user options
void menu() {
    int option, number;

    do {
        printf("\nList ADT Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter number to insert: ");
                scanf("%d", &number);
                insert(number);
                break;
            case 2:
                printf("Enter number to delete: ");
                scanf("%d", &number);
                delete(number);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (option != 4);
}

// Function to insert a number into the list
void insert(int number) {
    if (count >= MAX_SIZE) {
        printf("List is full! Cannot insert %d.\n", number);
        return;
    }

    // If the list is empty, add the number as the first element
    if (count == 0) {
        list[count++] = number;
        printf("%d inserted as the first element.\n", number);
        return;
    }

    // Find the correct position to insert the number
    int position;
    for (position = 0; position < count; position++) {
        if (list[position] > number) {
            break; // Found the position to insert
        }
    }

    // Shift elements to the right to make space for the new number
    for (int i = count; i > position; i--) {
        list[i] = list[i - 1];
    }

    // Insert the number
    list[position] = number;
    count++;
    printf("%d inserted at position %d.\n", number, position + 1);
}

// Function to delete a number from the list
void delete(int number) {
    if (count == 0) {
        printf("List is empty! Cannot delete %d.\n", number);
        return;
    }

    // Search for the number to delete
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (list[i] == number) {
            found = 1;
            // Shift elements to the left to remove the number
            for (int j = i; j < count - 1; j++) {
                list[j] = list[j + 1];
            }
            count--;
            printf("%d deleted from the list.\n", number);
            break;
        }
    }

    if (!found) {
        printf("%d not found in the list.\n", number);
    }
}

// Function to display the elements in the list
void display() {
    if (count == 0) {
        printf("List is empty.\n");
        return;
    }

    printf("List elements: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}