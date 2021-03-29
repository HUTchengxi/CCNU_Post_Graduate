#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAX 101

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isUnivalTree(struct TreeNode *root) {

    if (root == NULL) {
        return false;
    }

    if (root->left == NULL && root->right == NULL) {
        return true;
    }

    int val = root->val;

    struct TreeNode* arr[MAX];
    int len = 0;

    arr[len++] = root;

    //BFS
    while(len != 0) {
        printf("%d\n", len);
        struct TreeNode *cur = arr[--len];
        if(val != cur->val) {
            return false;
        }
        if(cur->left != NULL) {
            arr[len++] = cur->left;
        }
        if(cur->right != NULL) {
            arr[len++] = cur->right;
        }
    }

    return true;

}

int main() {

    struct TreeNode *root = malloc(sizeof(struct TreeNode*));
    struct TreeNode *left = malloc(sizeof(struct TreeNode*));
    struct TreeNode *right = malloc(sizeof(struct TreeNode*));
    left->val = 1;
    right->val = 1;
    root->val = 1;
    root->left = left;
    root->right = right;

    printf("%d\n", isUnivalTree(root));
    return 0;
}