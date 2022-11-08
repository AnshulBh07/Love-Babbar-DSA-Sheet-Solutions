#include<iostream>
using namespace std;

struct tree{
    int data;
    tree *left,*right;

    tree(int data){
        this->data = data;
        this->left = this->right = nullptr;
    }
};

bool pathSum(tree *root,int targetsum){
    if(!root)   return 0;

    int subsum = targetsum - root->data;
    bool ans = 0;

    if(subsum==0 && !root->left && !root->right)
    return 1;

    if(root->left)
    ans = ans || pathSum(root->left,subsum);
    if(root->right)
    ans = ans || pathSum(root->right,subsum);

    return ans;
}

int main()
{
    tree *root = new tree(5);
    root->left = new tree(4);
    root->left->left = new tree(11);
    root->left->left->left = new tree(7);
    root->left->left->right = new tree(2);
    root->right = new tree(8);
    root->right->left = new tree(13);
    root->right->right = new tree(4);
    root->right->right->right = new tree(1);

    cout<<pathSum(root,22);
    return 0;
}