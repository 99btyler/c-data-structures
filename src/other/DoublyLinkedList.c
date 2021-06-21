#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *nextNode;
    struct Node *previousNode;
};

void printDoublyLinkedList(struct Node *node) {

    printf("null <=> ");

    while (node != NULL) {
        printf("[%d]%d <=> ", (node->previousNode != NULL ? node->previousNode->data : -1), node->data);
        node = node->nextNode;
    }

    printf("null\n");

}

void add(int data, struct Node **firstNode) {

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->nextNode = NULL;
    newNode->previousNode = NULL;

    if (*firstNode == NULL) {

        *firstNode = newNode;

    } else {

        struct Node *lastNode = *firstNode;
        while (lastNode->nextNode != NULL) {
            lastNode = lastNode->nextNode;
        }

        lastNode->nextNode = newNode;
        newNode->previousNode = lastNode;

    }

    printDoublyLinkedList(*firstNode);

}

int main() {

    printf("\nDoublyLinkedList\n");

    struct Node *firstNode = NULL;

    add(17, &firstNode);
    add(19, &firstNode);

    return 0;

}