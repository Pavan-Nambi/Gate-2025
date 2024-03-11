#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define INITIAL_CAPACITY 3

typedef struct {
    int *items;
    size_t capacity;
    int front;
    int rear;
    int size;
} Queue;

void init(Queue *queue) {
    queue->capacity = INITIAL_CAPACITY;
    queue->items = (int *)malloc(queue->capacity * sizeof(int));
    assert(queue->items != NULL);
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
}

int isFull(const Queue *queue) {
    return queue->size == (int)(queue->capacity);
}

int isEmpty(const Queue *queue) {
    return queue->size == 0;
}

int enqueue(Queue *queue, int value) {
    if (isFull(queue)) {
        fprintf(stderr, "full\n");
        exit(EXIT_FAILURE);
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->items[queue->rear] = value;
    queue->size++;
    return EXIT_SUCCESS;
}

int dequeue(Queue *queue, int *value) {
    if (isEmpty(queue)) {
        fprintf(stderr, "empty.\n");
        return EXIT_FAILURE;
    }
    *value = queue->items[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return EXIT_SUCCESS;
}

int peek(const Queue *queue, int *value) {
    if (isEmpty(queue)) {
        fprintf(stderr, "empty.\n");
        return EXIT_FAILURE;
    }
    *value = queue->items[queue->front];
    return EXIT_SUCCESS;
}

void destroyQueue(Queue *queue) {
    free(queue->items);
    queue->items = NULL;
    queue->capacity = 0;
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
}

int main() {
    Queue queue;
    init(&queue);

    int choice = 0;
    int value;
    int scanf_result;

    do {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf_result = scanf("%d", &choice);

        if (scanf_result != 1) {
            fprintf(stderr, "Invalid need a integer.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf_result = scanf("%d", &value);
                if (scanf_result != 1) {
                    fprintf(stderr, "Invalid need a integer.\n");
                    while (getchar() != '\n'); 
                    break;
                }
                if (enqueue(&queue, value) == EXIT_FAILURE)
                    printf("full ign");
                break;
            case 2:
                if (dequeue(&queue, &value) == EXIT_SUCCESS)
                    printf("Dequeued : %d\n", value);
                else
                    printf("ntgg to dequeue its empty.. just like u..\n");
                break;
            case 3:
                if (peek(&queue, &value) == EXIT_SUCCESS)
                    printf("Front element: %d\n", value);
                else
                    printf("stop staring at me , i ain't got no feelings for u, i'm empty...\n");
                break;
            case 4:
                printf("Exited\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    destroyQueue(&queue);

    return EXIT_SUCCESS;
}
