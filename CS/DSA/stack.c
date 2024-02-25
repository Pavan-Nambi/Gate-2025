#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define INITIAL_CAPACITY 3

typedef struct {
    int *items;
    size_t capacity;
    int top;
} Stack;

void init(Stack *stack) {
    stack->capacity = INITIAL_CAPACITY;
    stack->items = (int *)malloc(stack->capacity * sizeof(int));
    assert(stack->items != NULL);
    stack->top = -1;
}

int isFull(const Stack *stack) {
    return stack->top == (int)(stack->capacity) - 1;
}

int isEmpty(const Stack *stack) {
    return stack->top == -1;
}

int push(Stack *stack, int value) {
    if (isFull(stack)) {
        fprintf(stderr, "no push dummass its full\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = value;
    return EXIT_SUCCESS;
}

int pop(Stack *stack, int *value) {
    if (isEmpty(stack)) {
        fprintf(stderr, "pop? poop ntg to poop u pooped everythingggg\n");
        return EXIT_FAILURE;
    }
    *value = stack->items[stack->top--];
    return EXIT_SUCCESS;
}

int peek(const Stack *stack, int *value) {
    if (isEmpty(stack)) {
        fprintf(stderr, "stop staring at me i m empty nothing in inside nothing in outside\n");
        return EXIT_FAILURE;
    }
    *value = stack->items[stack->top];
    return EXIT_SUCCESS;
}

void destroyStack(Stack *stack) {
    free(stack->items);
    stack->items = NULL;
    stack->capacity = 0;
    stack->top = -1;
}

int main() {
    Stack stack;
    init(&stack);

    int choice = 0;
    int value;
    int scanf_result;

    do {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf_result = scanf("%d", &choice);

        if (scanf_result != 1) {
            fprintf(stderr, "Invalid input. Please enter an integer.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf_result = scanf("%d", &value);
                if (scanf_result != 1) {
                    fprintf(stderr, "Invalid input. Please enter an integer.\n");
                    while (getchar() != '\n'); 
                    break;
                }
                if (push(&stack, value) == EXIT_FAILURE)
                    printf("Failed to push. Stack may be full.\n");
                break;
            case 2:
                if (pop(&stack, &value) == EXIT_SUCCESS)
                    printf("Pooped : %d\n", value);
                else
                    printf("Failed to pop. Stack may be empty.\n");
                break;
            case 3:
                if (peek(&stack, &value) == EXIT_SUCCESS)
                    printf("Top element: %d\n", value);
                else
                    printf("Failed to stare into stack. its EMPTY just like u...\n");
                break;
            case 4:
                printf("Exited\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    destroyStack(&stack);

    return EXIT_SUCCESS;
}
