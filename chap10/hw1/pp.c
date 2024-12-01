#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node **top, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        perror("failed");
        exit(1);
    }
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}
int pop(struct node **top) {
    if (*top == NULL) {
        fprintf(stderr, "empty\n");
        exit(1);
    }
    struct node *temp = *top;
    int poppedData = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedData;
}

int main() {
    struct node *top = NULL;
    int num;
    while (1) {
        if (scanf("%d", &num) != 1) {
            printf("Print stack\n");
            while (top != NULL) {
                printf("%d\n", pop(&top));
            }
            break;
        }
        if (num < 0) {
            break;
        }
        push(&top, num);
    }
    while (top != NULL) {
        printf("%d\n", pop(&top));
    }

    return 0;
}

