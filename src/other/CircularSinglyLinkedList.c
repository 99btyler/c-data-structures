#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *nextNode;
};

void printCircularSinglyLinkedList(struct Node *firstNode) {

    struct Node *node = firstNode;
    while (node != NULL) {
        printf("%d[%d] ", node->data, (node->nextNode != NULL ? node->nextNode->data : -1));
        node = node->nextNode;
        if (node == firstNode) {
            break;
        }
    }

    printf("...\n");

}

int get(int index, struct Node **firstNode) {

    struct Node *indexNode = *firstNode;
    int i = 0;
    while (indexNode != NULL) {
        if (i == index) {

            return indexNode->data;

        }
        indexNode = indexNode->nextNode;
        i += 1;
        if (indexNode == *firstNode) {
            break;
        }
    }

    return -1;

}

int indexOf(int data, struct Node **firstNode) {

    struct Node *dataNode = *firstNode;
    int i = 0;
    while (dataNode != NULL) {
        if (dataNode->data == data) {

            return i;

        }
        dataNode = dataNode->nextNode;
        i += 1;
        if (dataNode == *firstNode) {
            break;
        }
    }

    return -1;

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

void insert(int data, int index, struct Node **firstNode) {

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode->data = data;
    newNode->nextNode = NULL;

    if (index == 0) {

        struct Node *lastNode = *firstNode;
        while (lastNode->nextNode != *firstNode) {
            lastNode = lastNode->nextNode;
        }

        lastNode->nextNode = newNode;
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
            if (preIndexNode == *firstNode) {
                break;
            }
        }

    }

    printCircularSinglyLinkedList(*firstNode);

}

int main() {

    printf("\nCircularSinglyLinkedList\n");

    struct Node *firstNode = NULL;

    add(1, &firstNode);
    add(3, &firstNode);
    insert(2, 1, &firstNode);
    printf("Data at index 0: %d\n", get(0, &firstNode));
    printf("Index of data 3: %d\n", indexOf(3, &firstNode));

    return 0;

}