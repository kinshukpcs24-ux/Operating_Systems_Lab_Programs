#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int buffer[SIZE];
int in = 0;

int empty = SIZE;
int full = 0;
int mutex = 1;

void wait(int *s) {
    while (*s <= 0);
    (*s)--;
}

void signal(int *s) {
    (*s)++;
}

void producer() {
    if (empty == 0) {
        printf("Buffer is full!\n");
        return;
    }

    int item = rand() % 100;

    wait(&empty);
    wait(&mutex);

    buffer[in] = item;
    printf("Produced: %d at %d\n", item, in);
    in++;   // push

    signal(&mutex);
    signal(&full);
}

void consumer() {
    if (full == 0) {
        printf("Buffer is empty!\n");
        return;
    }

    int item;

    wait(&full);
    wait(&mutex);

    in--;   // pop
    item = buffer[in];
    printf("Consumed (recent): %d from %d\n", item, in);

    signal(&mutex);
    signal(&empty);
}

int main() {
    int choice;

    while (1) {
        printf("1. Produce\n2. Consume (recent item)\n3. Exit\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: producer(); break;
            case 2: consumer(); break;
            case 3: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
