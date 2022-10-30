#include<iostream>
using namespace std;

struct bst{
    int data;
    bst *right,*left;

    bst(int data){
        this->data = data;
        this->right = this->left = nullptr;
    }
};

bst *insert(bst *root,int data){
    if(!root)
    return new bst(data);

    if(data>root->data)
    root->right = insert(root->right,data);
    else
    root->left = insert(root->left,data);

    return root;
}

bool BSTorNOT(bst *root,int min,int max){
    if(!root)   return true;

    if(root->data < max && root->data > min){
        return BSTorNOT(root->left,min,root->data) && BSTorNOT(root->right,root->data,max);
    }else{
        return false;
    }
}

void inorder(bst *root){
    if(!root)   return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    bst *root = new bst(1);
    insert(root,2);
    insert(root,3);

    inorder(root);
    cout<<endl;

    int min = INT16_MIN, max = INT16_MAX;
    cout<<BSTorNOT(root,min,max);
    return 0;
}