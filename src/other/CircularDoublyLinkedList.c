#include <stdbool.h>
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

void insert(int data, int index, struct Node **firstNode) {

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->nextNode = NULL;
    newNode->previousNode = NULL;

    if (index == 0) {

        struct Node *lastNode = *firstNode;
        while (lastNode->nextNode != *firstNode) {
            lastNode = lastNode->nextNode;
        }

        lastNode->nextNode = newNode;
        newNode->previousNode = lastNode;

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
            if (indexNode == *firstNode) {
                break;
            }
        }

    }

    printCircularDoublyLinkedList(*firstNode);

}

void removeData(int data, struct Node **firstNode) {

    if ((*firstNode)->data == data) {

        struct Node *nodeToFree = *firstNode;

        struct Node *lastNode = *firstNode;
        while (lastNode->nextNode != *firstNode) {
            lastNode = lastNode->nextNode;
        }

        *firstNode = nodeToFree->nextNode;

        lastNode->nextNode = *firstNode;
        (*firstNode)->previousNode = lastNode;

        free(nodeToFree);
        nodeToFree = NULL;

    } else {

        struct Node *nodeToFree = *firstNode;
        while (nodeToFree != NULL) {
            if (nodeToFree->data == data) {

                struct Node *preDataNode = nodeToFree->previousNode;
                struct Node *postDataNode = nodeToFree->nextNode;

                preDataNode->nextNode = postDataNode;
                postDataNode->previousNode = preDataNode;

                free(nodeToFree);
                nodeToFree = NULL;

                break;

            }
            nodeToFree = nodeToFree->nextNode;
            if (nodeToFree == *firstNode) {
                break;
            }
        }

    }

    printCircularDoublyLinkedList(*firstNode);

}

void removeIndex(int index, struct Node **firstNode) {

    if (index == 0) {

        struct Node *nodeToFree = *firstNode;

        struct Node *lastNode = *firstNode;
        while (lastNode->nextNode != *firstNode) {
            lastNode = lastNode->nextNode;
        }

        *firstNode = nodeToFree->nextNode;

        lastNode->nextNode = *firstNode;
        (*firstNode)->previousNode = lastNode;

        free(nodeToFree);
        nodeToFree = NULL;

    } else {

        struct Node *nodeToFree = *firstNode;
        int i = 0;
        while (nodeToFree != NULL) {
            if (i == index) {

                struct Node *preIndexNode = nodeToFree->previousNode;
                struct Node *postIndexNode = nodeToFree->nextNode;

                preIndexNode->nextNode = postIndexNode;
                postIndexNode->previousNode = preIndexNode;

                free(nodeToFree);
                nodeToFree = NULL;

                break;

            }
            nodeToFree = nodeToFree->nextNode;
            i += 1;
            if (nodeToFree == *firstNode) {
                break;
            }
        }

    }

    printCircularDoublyLinkedList(*firstNode);

}

void clear(struct Node **firstNode) {

    struct Node *nodeToFree = *firstNode;
    while (nodeToFree != NULL) {

        struct Node *nextNodeToFree = nodeToFree->nextNode;

        free(nodeToFree);
        nodeToFree = NULL;

        nodeToFree = nextNodeToFree;
        if (nodeToFree == *firstNode) {
            break;
        }

    }

    *firstNode = NULL;

    printCircularDoublyLinkedList(*firstNode);

}

bool contains(int data, struct Node **firstNode) {

    struct Node *dataNode = *firstNode;
    while (dataNode != NULL) {
        if (dataNode->data == data) {

            return true;

        }
        dataNode = dataNode->nextNode;
        if (dataNode == *firstNode) {
            break;
        }
    }

    return false;

}

int size(struct Node **firstNode) {

    int size = 0;

    struct Node *node = *firstNode;
    while (node != NULL) {
        size += 1;
        node = node->nextNode;
        if (node == *firstNode) {
            break;
        }
    }

    return size;

}

int main() {

    printf("\nCircularDoublyLinkedList\n");

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