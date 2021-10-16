#include <stdio.h>

struct Node {
    int data;
    struct Node *leftChildNode;
    struct Node *rightChildNode;
};

void p(struct Node *currentNode) {

    if (currentNode == NULL) {
        return; // stop recursive calls
    }

    p(currentNode->leftChildNode);

    printf("[%d]%d[%d] ", (currentNode->leftChildNode != NULL ? currentNode->leftChildNode->data : -1), currentNode->data, currentNode->rightChildNode != NULL ? currentNode->rightChildNode->data : -1);

    p(currentNode->rightChildNode);

}

void printBinarySearchTree(struct Node *rootNode) {

    p(rootNode);

    printf("...\n");

}

int main() {

    printf("\nBinarySearchTree\n");

    struct Node *rootNode = NULL;

    return 0;

}