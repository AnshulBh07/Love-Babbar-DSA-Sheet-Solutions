#include<iostream>
#include<vector>
using namespace std;

struct tree{
    int val;
    tree *left,*right;

    tree(int val){
        this->val = val;
        this->left = this->right = nullptr;
    }
};

void inorder(tree *root,vector<int>&store){
    if(!root){
        return;
    }

    inorder(root->left,store);
    store.push_back(root->val);
    inorder(root->right,store);
}

int main(){
    tree *root = new tree(2);
    root->left = new tree(1);
    root->right = new tree(3);
    root->left->right = new tree(4);
    root->right->right = new tree(7);

    vector<int> store;

    inorder(root,store);

    for(int i=0;i<store.size();i++){
        cout<<store[i]<<"->";
    }
    return 0;
}