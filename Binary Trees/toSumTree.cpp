#include<iostream>
using namespace std;

struct tree{
    int data;
    tree *left,*right;

    tree(int data){
        this->left=this->right=NULL;
        this->data=data;
    }
};

int find(tree *root){
    if(!root)
    return 0;

    int ls = find(root->left);
    int rs = find(root->right);
    int x = root->data;
    root->data = ls+rs;
    return ls+rs+x;
}

void inorder(tree *root){
    if(!root)
    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void toSumTree(tree *root){
    find(root);
    inorder(root);
}

int main()
{
    tree *root = new tree(10);
    root->left = new tree(-2);
    root->right = new tree(6);
    root->left->left = new tree(8);
    root->left->right = new tree(-4);
    root->right->left = new tree(7);
    root->right->right = new tree(5);

    toSumTree(root);
    return 0;
}