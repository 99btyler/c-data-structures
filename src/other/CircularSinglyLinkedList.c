#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *nextNode;
};

void printCircularSinglyLinkedList(struct Node *firstNode) {

    struct Node *node = firstNode;

    if (node == NULL) {

        printf("null\n");

    } else {

        while (node != NULL) {
            printf("%d{%d} => ", node->data, (node->nextNode == firstNode ? node->nextNode->data : -1));
            node = node->nextNode;
            if (node == firstNode) {
                break;
            }
        }

        printf("\n");

    }

}

void add(int data, struct Node **firstNode) {

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode->data = data;
    newNode->nextNode = NULL;

    if (*firstNode == NULL) {

        *firstNode = newNode;
        (*firstNode)->nextNode = newNode;

    } else {

        struct Node *lastNode = *firstNode;
        while (lastNode->nextNode != *firstNode) {
            lastNode = lastNode->nextNode;
        }

        lastNode->nextNode = newNode;
        newNode->nextNode = *firstNode;

    }

    printCircularSinglyLinkedList(*firstNode);

}

int main() {

    printf("\nCircularSinglyLinkedList\n");

    struct Node *firstNode = NULL;

    add(2020, &firstNode);
    add(2022, &firstNode);

    return 0;

}