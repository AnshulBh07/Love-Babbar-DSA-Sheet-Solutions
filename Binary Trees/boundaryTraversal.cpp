#include<iostream>
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

void leftBoundary(tree *root,vector<int>&ans){
    if(!root)
    return;

    if(root->left){
        ans.push_back(root->data);
        leftBoundary(root->left,ans);
    }
    else if(root->right){
        ans.push_back(root->data);
        leftBoundary(root->right,ans);
    }
}

void leaf(tree *root,vector<int>&ans){
    if(!root)
    return;

    leaf(root->left,ans);
    if(!root->left && !root->right)
    ans.push_back(root->data);
    leaf(root->right,ans);
}

void rightBoundary(tree *root,vector<int>&ans){
    if(!root)
    return;

    if(root->right){
        rightBoundary(root->right,ans);
        ans.push_back(root->data);
    }
    else if(root->left){
        rightBoundary(root->left,ans);
        ans.push_back(root->data);
    }
}

//this can be done by divinding the traversal into 3 parts, left traversal, leaf nodes and 
//right traversal in reverse order
void boundaryTraversal(tree *root){
    vector<int> ans;
    ans.push_back(root->data);
    leftBoundary(root->left,ans);
    leaf(root->left,ans);
    leaf(root->right,ans);
    rightBoundary(root->right,ans);

    for(auto x:ans){
        cout<<x<<" ";
    }
}

int main()
{
    tree *root = new tree(1);
    root->left = new tree(2);
    root->right = new tree(3);
    root->left->left = new tree(4);
    root->left->right = new tree(5);
    root->left->right->left = new tree(8);
    root->left->right->right = new tree(9);
    root->right->left = new tree(6);
    root->right->right = new tree(7);

    boundaryTraversal(root);
    return 0;
}