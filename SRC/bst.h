/**
 * Header file for Binary Search Tree creation, modification, and interaction.
 * */
#ifndef BST_H
#define BST_H

#define Low2High 1
#define High2Low 2

/**
 * The struct node is one unit of a tree. Each node has pointers to
 * child nodes andhas a data field.
 */
typedef struct node {
    struct node *parent;
    struct node *left;
    struct node *right;
    int data;
    unsigned int matched;
} node;

/**
 * A wrapper struct that allows for an empty bst with no nodes. Optional.
 */
typedef struct bst {
    struct node *root;
    int nodeCount;
} bst;

bst * createBST(void);
void addBSTNode(bst *bstPtr, int data);
void printBST(bst *bstPtr, int mode);
node * searchBST(bst *bstPtr, int data);
void distroyBST(bst * bstPtr);

/**
 * Place holder functions for added removal of nodes
 * */
void removeByInt(bst *bstPtr, int data);
void removeByPtr(bst *node);

#define removeNode(_1, ...) _Generic((_1,                                    \
                                    default: removeByInt                     \
                                    bst *: _Generic((FIRST(__VA_ARGS__,)),   \
                                        int: removeByInt))(_1, __VA_ARGS__)

#endif