#include<iostream>
using namespace std;

struct bst{
    int data;
    bst *left,*right;

    bst(int data){
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

bst *findLCA(bst *root,int n1,int n2){
    if(!root)   return root;

    //if n1 and n2 both are greater than curr node then the nodes lye in right subtree
    if(root->data < n1 && root->data < n2)
    return findLCA(root->right,n1,n2);

    if(root->data > n1 && root->data > n2)
    return findLCA(root->left,n1,n2);

    //if curr node lyes between n1 and n2 its the commo ancestor 
    return root;
}

int main()
{
    bst *root = new bst(5);
    insert(root,4);
    insert(root,6);
    insert(root,3);
    insert(root,7);
    insert(root,8);

    bst *ans = findLCA(root,7,8);
    cout<<ans->data;
    return 0;
}