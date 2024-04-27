#include <stdio.h>
#include <stdlib.h>


struct SYMBOL {
    char alphabet;
    int frequency;
};


struct Node {
    struct SYMBOL symbol;
    struct Node *left;
    struct Node *right;
};

struct MinPriorityQueueNode {
    struct Node *node;
    struct MinPriorityQueueNode *next;
};


struct Node *createNode(struct SYMBOL symbol) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->symbol = symbol;
    newNode->left = newNode->right = NULL;
    return newNode;
}


struct MinPriorityQueueNode *createQueueNode(struct Node *node) {
    struct MinPriorityQueueNode *newQueueNode = (struct MinPriorityQueueNode *)malloc(sizeof(struct MinPriorityQueueNode));
    newQueueNode->node = node;
    newQueueNode->next = NULL;
    return newQueueNode;
}

void insertQueueNode(struct MinPriorityQueueNode **queue, struct Node *node) {
    struct MinPriorityQueueNode *newQueueNode = createQueueNode(node);
    if (*queue == NULL || (*queue)->node->symbol.frequency > node->symbol.frequency) {
        newQueueNode->next = *queue;
        *queue = newQueueNode;
    } else {
        struct MinPriorityQueueNode *current = *queue;
        while (current->next != NULL && current->next->node->symbol.frequency <= node->symbol.frequency) {
            current = current->next;
        }
        newQueueNode->next = current->next;
        current->next = newQueueNode;
    }
}


struct Node *extractMin(struct MinPriorityQueueNode **queue) {
    if (*queue == NULL) {
        return NULL;
    }
    struct Node *minNode = (*queue)->node;
    *queue = (*queue)->next;
    return minNode;
}

struct Node *buildHuffmanTree(struct SYMBOL symbols[], int n) {
    struct MinPriorityQueueNode *queue = NULL;

    
    for (int i = 0; i < n; i++) {
        struct Node *node = createNode(symbols[i]);
        insertQueueNode(&queue, node);
    }

    
    while (queue->next != NULL) {
        struct Node *left = extractMin(&queue);
        struct Node *right = extractMin(&queue);
        struct SYMBOL combinedSymbol = {'\0', left->symbol.frequency + right->symbol.frequency};
        struct Node *combinedNode = createNode(combinedSymbol);
        combinedNode->left = left;
        combinedNode->right = right;
        insertQueueNode(&queue, combinedNode);
    }

    return queue->node;
}


void inOrderTraversal(struct Node *node) {
    if (node != NULL) {
        inOrderTraversal(node->left);
        printf("%c\n%d\n", node->symbol.alphabet, node->symbol.frequency);
        inOrderTraversal(node->right);
    }
}

int main() {
    int n;
    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    struct SYMBOL symbols[n];
    for (int i = 0; i < n; i++) {
        printf("Enter alphabet %d: ", i + 1);
        scanf(" %c", &symbols[i].alphabet);
        printf("Enter its frequency: ");
        scanf("%d", &symbols[i].frequency);
    }

    
    struct Node *root = buildHuffmanTree(symbols, n);

    printf("In-order traversal of the tree (Huffman):\n");
    inOrderTraversal(root);

    return 0;
}
