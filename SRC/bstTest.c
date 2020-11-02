/**
 * Test for Binary Search Tree functionality.
 * */
#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Create and populate BST for testing.
 * */
bst * initBST() {
    bst *myBST = createBST();
    if(!myBST) {
        fprintf(stderr, "Failed to create BST exiting...");

        exit(-1);
    }

    if(myBST) {
        puts("Created BST");
    }
    if(!myBST->root) {
        puts("Root Node is null\n");
    }

    int nums[] = {52, 45, 75, 47, 63, 88, 46, 49, 100};
    // Get the length of the int array dynamically
    int len = sizeof(nums)/sizeof(nums[0]);
    for(int i = 0; i < len; i++) {
        printf("Adding node with data %d\n", nums[i]);
        addBSTNode(myBST, nums[i]);
    }

    return myBST;
}

int main(void) {
    char *border = {"\n=================== %s ===================\n\n"};

    // Generate BST for tests
    bst *myBST = initBST();

    // Tests
    printf(border, "Low to High");
    printBST(myBST, Low2High);
    printf(border, "High to Low");
    printBST(myBST, High2Low);

    printf(border, "Searches");
    int nums[] = {88, 90, 42, 75, 52};
    int len = sizeof(nums)/sizeof(nums[0]);
    for(int i = 0; i < len; i++) {
        node *match = searchBST(myBST, nums[i]);
        if(match) {
            printf("%d matched %d\n", nums[i], match->data);
        }
    }

    // Loop through and free all allocations
    printf(border, "Freeing BST");
    distroyBST(myBST);

    return 0;
}