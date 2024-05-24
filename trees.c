#include <stdlib.h>
#include <stdio.h>

typedef struct  Node {
    int data;
    struct Node *left;
    struct Node *right;
} node;

// creates a new node
node *getNewNode(int x) {

    // allocates memory for the new node
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    return newNode;
    
}


// inserts node at appropriate place
node *insert(node *root, int x) {
    if (root == NULL) {
        return getNewNode(x);
    }
    // inserts node to the left of its parent node if it is less or equal to the parent node
    if (x <= root->data) {
        root->left = insert(root->left, x);
    } else {
    // inserts node to the right of its parent node if it is greater than the parent node
        root->right = insert(root->right, x);
    }
    return root;
}

// searches for a given node
node *search(node* root, int x) {
    if (root == NULL || root->data == x) {
        return root;
    } 
    // if the given value is less than its parent nodee, search left
    if (x < root->data) {
        return search(root->left, x);

    } 
    // searches the right side of the tree
    return search(root->right, x);
}


// finds the minimum value in the tree
node *findMin(node* root) {
    if (root == NULL) {
        return NULL;
    } 
    // search the left most node as it would be the minimum
    if (root->left != NULL) {
        return findMin(root->left);
    }
    printf("%d ", root->data);
    return root;
}

// preforms post order traversal
void postOrder(node *root) {
    if (root != NULL) {
        postOrder(root->right);
        postOrder(root->left);
        printf("%d ", root->data);
    } 
}

// preforms in order traversal
void inOrder(node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// preforms pre-order traversal
void preOrder(node* root) {
    if (root!= NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
        
    }
}
int main() {

    // creates root node and sets it to NULL
    struct Node *root = NULL;

    // creates a root node
    root = insert(root,75);

    // inserts nodes into the tree
    insert(root, 14);
    insert(root, 10);
    insert(root, 45);
    insert(root, 17);
    insert(root, 66);
    insert(root, 7);
    insert(root, 56);
    printf("searching for 15: ");
    if (search(root, 10) != NULL) {
        printf("15 found\n");
    } else {
        printf("Not found\n");
    }

    printf("The min is: ");
    findMin(root);
    printf("\n");
    printf("Post order: ");
    postOrder(root);
    printf("\n");
    printf("In order: ");
    inOrder(root);
    printf("\n");
    printf("Pre order: ");
    preOrder(root);

    return 0;
}