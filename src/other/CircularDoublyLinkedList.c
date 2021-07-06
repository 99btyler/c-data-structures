#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *nextNode;
    struct Node *previousNode;
};

void printCircularDoublyLinkedList(struct Node *firstNode) {

    struct Node *node = firstNode;
    while (node != NULL) {
        printf("[%d]%d[%d] ", (node->previousNode != NULL ? node->previousNode->data : -1), node->data, (node->nextNode != NULL ? node->nextNode->data : -1));
        node = node->nextNode;
        if (node == firstNode) {
            break;
        }
    }

    printf("...\n");

}

void add(int data, struct Node **firstNode) {

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->nextNode = NULL;
    newNode->previousNode = NULL;

    if (*firstNode == NULL) {

        *firstNode = newNode;
        (*firstNode)->nextNode = newNode;
        (*firstNode)->previousNode = newNode;

    } else {

        struct Node *lastNode = *firstNode;
        while (lastNode->nextNode != *firstNode) {
            lastNode = lastNode->nextNode;
        }

        lastNode->nextNode = newNode;
        newNode->previousNode = lastNode;

        newNode->nextNode = *firstNode;
        (*firstNode)->previousNode = newNode;

    }

    printCircularDoublyLinkedList(*firstNode);

}

int main() {

    printf("\nCircularDoublyLinkedList\n");

    struct Node *firstNode = NULL;
    
    add(1, &firstNode);
    add(3, &firstNode);

    return 0;

}