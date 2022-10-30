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

bst *insert(bst *root,int val){
    if(!root)  
    return new bst(val);

    if(val > root->data)
    root->right = insert(root->right,val);
    else
    root->left = insert(root->left,val);

    return root;
}

//counting while doing inorder traversal
void inorder(bst *root,int &count,int low,int high){
    if(!root)   return;

    inorder(root->left,count,low,high);
    
    if(root->data>=low && root->data<=high)
    count++;
    
    inorder(root->right,count,low,high);
}

int countNodes(bst *root,int low, int high){
    if(!root)   return 0;
    int count = 0;

    inorder(root,count,low,high);
    return count;
}

int main()
{
    bst *root = new bst(10);
    insert(root,5);
    insert(root,50);
    insert(root,1);
    insert(root,40);
    insert(root,100);

    int high = 45,low = 5;
    cout<<countNodes(root,low,high);
    return 0;
}