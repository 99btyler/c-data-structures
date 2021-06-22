#include <stdbool.h>
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

int get(int index, struct Node **firstNode) {

    struct Node *indexNode = *firstNode;
    int i = 0;
    while (indexNode != NULL) {
        if (i == index) {

            return indexNode->data;

        }
        indexNode = indexNode->nextNode;
        i += 1;
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
    }

    return -1;

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

void insert(int data, int index, struct Node **firstNode) {

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->nextNode = NULL;
    newNode->previousNode = NULL;

    if (index == 0) {

        newNode->nextNode = *firstNode;
        (*firstNode)->previousNode = newNode;

        *firstNode = newNode;

    } else {

        struct Node *indexNode = *firstNode;
        int i = 0;
        while (indexNode != NULL) {
            if (i == index) {

                struct Node *preIndexNode = indexNode->previousNode;

                preIndexNode->nextNode = newNode;
                newNode->previousNode = preIndexNode;

                newNode->nextNode = indexNode;
                indexNode->previousNode = newNode;

                break;

            }
            indexNode = indexNode->nextNode;
            i += 1;
        }

    }

    printDoublyLinkedList(*firstNode);

}

bool contains(int data, struct Node **firstNode) {

    struct Node *dataNode = *firstNode;
    while (dataNode != NULL) {
        if (dataNode->data == data) {

            return true;

        }
        dataNode = dataNode->nextNode;
    }

    return false;

}

int size(struct Node **firstNode) {
    
    int size = 0;

    struct Node *node = *firstNode;
    while (node != NULL) {
        size += 1;
        node = node->nextNode;
    }

    return size;

}

int main() {

    printf("\nDoublyLinkedList\n");

    struct Node *firstNode = NULL;

    add(17, &firstNode);
    printf("Contains 17: %d\n", contains(17, &firstNode));
    printf("Size: %d\n", size(&firstNode));
    add(19, &firstNode);
    printf("Data at index 1: %d\n", get(1, &firstNode));
    insert(18, 1, &firstNode);
    printf("Index of data 18: %d\n", indexOf(18, &firstNode));

    return 0;

}