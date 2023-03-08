#include<iostream>
#include<vector>
using namespace std;

struct bst{
    int data;
    bst *left,*right;

    bst(int datat){
        this->data = data;
        this->left = this->right = nullptr;
    }
};

bst *insert(bst *root,int val){
    if(!root)
    return new bst(val);

    if(val > root->data)
    root->right = insert(root->right,val);
    else
    root->left = insert(root->left,val);

    return root;
}

void inorder(bst* root,vector<int>&helper){
    if(!root)
    return;

    inorder(root->left,helper);
    helper.push_back(root->data);
    inorder(root->right,helper);
}

int main(){
    bst *root = new bst(4);
    insert(root,2);
    insert(root,6);
    insert(root,1);
    insert(root,3);

    vector<int> helper;
    inorder(root,helper);

    for(int x: helper){
        cout<<x<<"->";
    }
    return 0;
}