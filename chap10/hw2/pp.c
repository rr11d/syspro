#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void addq(struct node **head, struct node **tail, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        perror("failed");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (*tail == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

int deleteq(struct node **head, struct node **tail) {
    if (*head == NULL) {
        fprintf(stderr, "empty\n");
        exit(1);
    }

    struct node *temp = *head;
    int data = temp->data;
    *head = (*head)->next;
    if (*head == NULL) {
        *tail = NULL;
    }
    free(temp);
    return data;
}

int main() {
    struct node *head = NULL;
    struct node *tail = NULL;

    int num;
    while (1) {
        if (scanf("%d", &num) != 1) {
			printf("Print queue\n");
            while (head != NULL) {
                printf("%d\n", deleteq(&head, &tail));
            }
            break;
        }
        if (num < 0) {
            break;
        }
        addq(&head, &tail, num);
    }
	while(head != NULL){
		printf("%d", deleteq(&head, &tail));
	}
	return 0;
}
