#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct  TreeNode *right;
};


struct TreeNode* constructFromPrePost(int* pre, int preSize, int* post, int postSize){
    if(preSize==0 || postSize==0) return NULL;

    struct TreeNode* root=malloc(sizeof(struct TreeNode));
    root->val=pre[0];
    int left=1;
    while(left<preSize && pre[left]!=post[postSize-2]) ++left;
    left-=1;

    root->left=constructFromPrePost(pre+1,left,post,left);
    root->right=constructFromPrePost(pre+1+left,preSize-left-1,post+left,postSize-left-1);

    return root;
}

int main() {

    return 0;
}