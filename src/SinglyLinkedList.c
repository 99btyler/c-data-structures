#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *nextNode;
};

void printSinglyLinkedList(struct Node *node) {

    while (node != NULL) {
        printf("%d => ", node->data);
        node = node->nextNode;
    }

    printf("null\n");

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

    printSinglyLinkedList(*firstNode);

}

void insert(int data, int index, struct Node **firstNode) {

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->nextNode = NULL;

    if (index == 0) {

        newNode->nextNode = *firstNode;
        *firstNode = newNode;

    } else {

        struct Node *preIndexNode = *firstNode;
        int i = 0;
        while (preIndexNode != NULL) {
            if (i == index-1) {

                struct Node *indexNode = preIndexNode->nextNode;

                preIndexNode->nextNode = newNode;
                newNode->nextNode = indexNode;

                break;

            }
            preIndexNode = preIndexNode->nextNode;
            i += 1;
        }

    }

    printSinglyLinkedList(*firstNode);

}

int main() {

    printf("SinglyLinkedList\n");

    struct Node *firstNode = NULL;

    add(1, &firstNode);
    add(3, &firstNode);
    insert(2, 1, &firstNode);

    return 0;

}