/**
 * Functions for Binary Search Tree creation, modification, and interaction.
 * */
#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

static void recursiveInsert(node *n, int data);
static int compareNodes(int nodeData, int data);
static void recursiveFree(node *n);
static void low2HighPrint(node *n);
static void high2LowPrint(node *n);
static node *recursiveSearch(node *n, int data, node *match);

/**
 * Creates a wrapper to a BST root node.
 * */
bst * createBST(void) {
    bst *bstPtr = calloc(1, sizeof(*bstPtr));
    if(!bstPtr) {
        return NULL;
    }
    bstPtr->root = NULL;

    return bstPtr;
}

/**
 * Add a new node to BST
 * */
void addBSTNode(bst *bstPtr, int data) {
    if(!bstPtr) {
        return;
    }

    if(!bstPtr->root) {
        bstPtr->root = calloc(1, sizeof(node));
        if(!bstPtr->root) {
            return;
        }
        bstPtr->root->data = data;
        return;
    }

    recursiveInsert(bstPtr->root, data);
}

/**
 * Recursively goes through and inserts new node in correct order with BST.
 * */
static void recursiveInsert(node *n, int data) {

    // Result will be < 0 if the new data is larger then n->data and
    // > 0 if n->data is larger.
    int result = compareNodes(n->data, data);
    if(result < 0) {
        // Go to the right child
        if(n->right) {
            recursiveInsert(n->right, data);
        }
        else
        {
            n->right = calloc(1, sizeof(*n->right));
            if(!n->right) {
                return;
            }
            n->right->data = data;
            n->right->matched = 0;
        }
    }
    else if(result > 0) {
        // Go to the left child
        if(n->left) {
            recursiveInsert(n->left, data);
        }
        else {
            n->left = calloc(1, sizeof(*n->left));
            if(!n->left) {
                return;
            }
            n->left->data = data;
            n->left->matched = 0;
        }
    }
}

/**
 * 
 * */
static int compareNodes(int nodeData, int data) {
    return (nodeData - data);
}

/**
 * Prints a BST based on mode.
 * */
void printBST(bst *bstPtr, int mode) {
    if(mode == Low2High) {
        puts("");
        low2HighPrint(bstPtr->root);
        puts("");
    }
    else {
        puts("");
        high2LowPrint(bstPtr->root);
        puts("");
    }
}

/**
 * Prints BST values from low to high.
 * */
static void low2HighPrint(node *n) {
    if(!n) {
        return;
    }

    if(n->left) {
        low2HighPrint(n->left);
    }

    printf("%d\n", n->data);

    if(n->right) {
        low2HighPrint(n->right);
    }
}

/**
 * Prints BST values from high to low.
 * */
static void high2LowPrint(node *n) {
    if(!n) {
        return;
    }

    if(n->right) {
        high2LowPrint(n->right);
    }

    printf("%d\n", n->data);

    if(n->left) {
        high2LowPrint(n->left);
    }
}

/**
 * Calls a preorder recursive seach.
 * */
node * searchBST(bst *bstPtr, int data) {
    node *match = NULL;
    if(!bstPtr) {
        return match;
    }
    match = recursiveSearch(bstPtr->root, data, match);

    return match;
}

/**
 * A preorder search
 * */
static node * recursiveSearch(node *n, int data, node *match) {
    if(!n) {
        return match;
    }

    if(n->data == data) {
        match = n;
    }

    if(match) {
        return match;
    }

    match = recursiveSearch(n->left, data, match);
    match = recursiveSearch(n->right, data, match);

    return match;
}

/**
 * Frees all nodes and BST wrapper
 * */
void distroyBST(bst * bstPtr) {
    recursiveFree(bstPtr->root);
    free(bstPtr);
}

/** 
 * Recursive function to free node without orphans
 * */
static void recursiveFree(node *n) {
    if(!n)
    {
        return;
    }

    recursiveFree(n->left);
    recursiveFree(n->right);
    free(n);
}