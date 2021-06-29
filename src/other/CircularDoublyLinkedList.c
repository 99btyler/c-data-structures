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

int main() {

    printf("\nCircularDoublyLinkedList\n");

    struct Node *firstNode = NULL;
    
    add(1, &firstNode);
    add(3, &firstNode);

    return 0;

}