#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *nextNode;
};

void printStack(struct Node *node) {

    while (node != NULL) {
        printf("%d => ", node->data);
        node = node->nextNode;
    }

    printf("null\n");

}

int peek(struct Node **firstNode) {
    return (*firstNode != NULL ? (*firstNode)->data : -1);
}

void push(int data, struct Node **firstNode) {

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->nextNode = NULL;

    if (*firstNode == NULL) {

        *firstNode = newNode;

    } else {

        newNode->nextNode = *firstNode;
        *firstNode = newNode;

    }

    printStack(*firstNode);

}

int pop(struct Node **firstNode) {

    if (*firstNode != NULL) {

        struct Node *nodeToFree = *firstNode;
        const int removedData = nodeToFree->data;

        *firstNode = nodeToFree->nextNode;
        free(nodeToFree);

        printStack(*firstNode);

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

    printStack(*firstNode);

}

int main() {

    printf("\nStack\n");

    struct Node *firstNode = NULL;
    
    push(1, &firstNode);
    push(2, &firstNode);
    printf("Peek: %d\n", peek(&firstNode));
    push(3, &firstNode);
    pop(&firstNode);
    clear(&firstNode);

    return 0;

}