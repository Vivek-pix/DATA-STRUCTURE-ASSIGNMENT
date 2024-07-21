#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Define the maximum size of the stack

// Structure to represent a stack
typedef struct {
    int top;         // Index of the top element
    int items[MAX_SIZE]; // Array to store stack elements
} Stack;

// Function prototypes
void initialize(Stack *s);
int is_full(Stack *s);
int is_empty(Stack *s);
void push(Stack *s, int item);
int pop(Stack *s);
void display(Stack *s);
void menu();

int main() {
    Stack stack;
    initialize(&stack);
    menu(&stack);
    return 0;
}

// Function to initialize the stack
void initialize(Stack *s) {
    s->top = -1; // Stack is initially empty
}

// Function to check if the stack is full
int is_full(Stack *s) {
    return s->top == MAX_SIZE - 1; // Returns 1 if full, 0 otherwise
}

// Function to check if the stack is empty
int is_empty(Stack *s) {
    return s->top == -1; // Returns 1 if empty, 0 otherwise
}

// Function to push an item onto the stack
void push(Stack *s, int item) {
    if (is_full(s)) {
        printf("Stack overflow! Cannot push %d.\n", item);
        return;
    }
    s->items[++(s->top)] = item; // Increment top and add item
    printf("%d pushed onto the stack.\n", item);
}

// Function to pop an item from the stack
int pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow! Cannot pop from an empty stack.\n");
        return -1; // Return -1 to indicate an error
    }
    return s->items[(s->top)--]; // Return the top item and decrement top
}

// Function to display the elements in the stack
void display(Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

// Function to display the menu and get user options
void menu(Stack *s) {
    int option, number;

    do {
        printf("\nStack ADT Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter number to push: ");
                scanf("%d", &number);
                push(s, number);
                break;
            case 2:
                number = pop(s);
                if (number != -1) {
                    printf("%d popped from the stack.\n", number);
                }
                break;
            case 3:
                display(s);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (option != 4);
}