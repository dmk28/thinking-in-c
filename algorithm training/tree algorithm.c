#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *right;
    struct TreeNode *left;
};

void depthFirstSearch(struct TreeNode *node) {
    
    if (node == NULL) return;
    if (node -> left == NULL && node -> right == NULL) {
        printf("%d\n", node-> val);
        return;
    }

    depthFirstSearch(node->left);
    depthFirstSearch(node->right);

}



int main() {
    struct TreeNode root;
    root.val = 10;
    root.left = NULL;
    root.right = NULL;

    struct TreeNode node1;
    node1.val=15;
    node1.left = NULL;
    node1.right = NULL;

    struct TreeNode node2;
    node2.val=16;
    node2.left= NULL;
    node2.right = NULL;

    struct TreeNode node3;
    node3.val=20;
    node3.left=NULL;
    node3.right = NULL;

    struct TreeNode node4;
    node4.val=4;
    node4.left=NULL;
    node4.right= NULL;

    root.left = &node1;
    root.right = &node4;
   
    depthFirstSearch(&root);
    
    
    return 0;
}

