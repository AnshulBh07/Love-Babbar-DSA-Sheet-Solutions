#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

struct tree{
    int data;
    tree *right,*left;

    tree(int data){
        this->data=data;
        this->right=this->left=nullptr;
    }
};

int height(tree *root){
    if(root==nullptr)
    return 0;

    int ls = height(root->left);
    int rs = height(root->right);

    if(ls==0 || rs==0 || abs(ls-rs)>1)
    return -1;

    return max(ls,rs)+1;
}

bool isBalanced(tree *root){
    if(height(root)==-1)
    return false;

    return true;
}

int main()
{
    tree *root = new tree(7);
    root->left = new tree(9);
    root->right = new tree(7);
    root->left->left = new tree(8);
    root->left->right = new tree(8);
    root->left->left->left = new tree(10);
    root->left->left->right = new tree(9);
    root->right->left = new tree(6);

    cout<<isBalanced(root);
    return 0;
}