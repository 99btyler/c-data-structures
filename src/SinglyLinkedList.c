#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *nextNode;
};

void printSinglyLinkedList(struct Node *node) {

    while (node != NULL) {
        printf("%d[%d] ", node->data, (node->nextNode != NULL ? node->nextNode->data : -1));
        node = node->nextNode;
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

void removeData(int data, struct Node **firstNode) {

    if ((*firstNode)->data == data) {

        struct Node *nodeToFree = *firstNode;

        *firstNode = (*firstNode)->nextNode;
        
        free(nodeToFree);
        nodeToFree = NULL;

    } else {

        struct Node *preDataNode = *firstNode;
        while (preDataNode != NULL) {
            if (preDataNode->nextNode->data == data) {

                struct Node *nodeToFree = preDataNode->nextNode;

                preDataNode->nextNode = nodeToFree->nextNode;

                free(nodeToFree);
                nodeToFree = NULL;

                break;

            }
            preDataNode = preDataNode->nextNode;
        }

    }

    printSinglyLinkedList(*firstNode);

}

void removeIndex(int index, struct Node **firstNode) {

    if (index == 0) {

        struct Node *nodeToFree = *firstNode;

        *firstNode = nodeToFree->nextNode;

        free(nodeToFree);
        nodeToFree = NULL;

    } else {

        struct Node *preIndexNode = *firstNode;
        int i = 0;
        while (preIndexNode != NULL) {
            if (i == index-1) {

                struct Node *nodeToFree = preIndexNode->nextNode;

                preIndexNode->nextNode = nodeToFree->nextNode;

                free(nodeToFree);
                nodeToFree = NULL;
                
                break;

            }
            preIndexNode = preIndexNode->nextNode;
            i += 1;
        }

    }

    printSinglyLinkedList(*firstNode);

}

void clear(struct Node **firstNode) {

    struct Node *nodeToFree = *firstNode;
    while (nodeToFree != NULL) {

        struct Node *nextNodeToFree = nodeToFree->nextNode;

        free(nodeToFree);
        nodeToFree = NULL;

        nodeToFree = nextNodeToFree;

    }
    *firstNode = NULL;

    printSinglyLinkedList(*firstNode);

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

    printf("\nSinglyLinkedList\n");

    struct Node *firstNode = NULL;

    add(1, &firstNode);
    add(3, &firstNode);
    insert(2, 1, &firstNode);
    printf("Size: %d\n", size(&firstNode));
    printf("Data at index 0: %d\n", get(0, &firstNode));
    printf("Index of data 3: %d\n", indexOf(3, &firstNode));
    removeData(3, &firstNode);
    printf("Contains data 3: %d\n", contains(3, &firstNode));
    removeIndex(0, &firstNode);
    clear(&firstNode);

    return 0;

}