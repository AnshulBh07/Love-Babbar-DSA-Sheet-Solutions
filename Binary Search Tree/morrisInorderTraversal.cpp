//inorder traversal without using recursion and stack that is in constant extra space
//https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
#include<iostream>
using namespace std;

struct bst{
    int data;
    bst *right,*left;

    bst(int data){
        this->data = data;
        this->left = this->right = nullptr;
    }
};

bst *insert(bst *root,int val){
    if(!root)
    return new bst(val);

    if(val>root->data)
    root->right = insert(root->right,val);
    else
    root->left = insert(root->left,val);

    return root;
}



int main()
{

    return 0;
}