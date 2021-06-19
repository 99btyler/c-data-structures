#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *nextNode;
};

void printQueue(struct Node *node) {

    while (node != NULL) {
        printf("%d => ", node->data);
        node = node->nextNode;
    }

    printf("null\n");

}

int peek(struct Node **firstNode) {

    return (*firstNode != NULL ? (*firstNode)->data : -1);
    
}

void add(int data, struct Node **firstNode) {

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->nextNode = NULL;

    if (*firstNode == NULL) {

        *firstNode = newNode;

    } else {

        struct Node *lastNode = *firstNode;
        while (lastNode->nextNode != NULL) {
            lastNode = lastNode->nextNode;
        }

        lastNode->nextNode = newNode;

    }

    printQueue(*firstNode);

}

int pop(struct Node **firstNode) {

    if (*firstNode != NULL) {

        struct Node *nodeToFree = *firstNode;
        const int removedData = nodeToFree->data;

        *firstNode = nodeToFree->nextNode;
        free(nodeToFree);

        printQueue(*firstNode);

        return removedData;

    }

    return -1;

}

void clear(struct Node **firstNode) {

    struct Node *nodeToFree = *firstNode;
    while (nodeToFree != NULL) {

        struct Node *nextNode = nodeToFree->nextNode;

        free(nodeToFree);
        nodeToFree = nextNode;

    }
    *firstNode = NULL;

    printQueue(*firstNode);

}

int main() {

    printf("\nQueue\n");

    struct Node *firstNode = NULL;

    add(1, &firstNode);
    add(2, &firstNode);
    printf("Peek: %d\n", peek(&firstNode));
    add(3, &firstNode);
    pop(&firstNode);
    clear(&firstNode);

    return 0;

}