#include<iostream>
using namespace std;

class bst{

    public :
    int data;
    bst *left,*right;

    //deafult constructor
    bst(){

    }

    bst(int data){
        this->data = data;
        this->left=this->right = nullptr;
    }

    bst* insert(bst *root,int val);
    bool isPresent(bst *root,int key);
};

//recursively insert in tree
bst* bst ::  insert(bst *root,int val){
    if(!root)
    return new bst(data);

    if(val>root->data){
        root->right = insert(root->right,val);
    }
    else if(val<root->data){
        root->left = insert(root->left,val);
    }
    return root;
}

bool bst :: isPresent(bst *root,int key){
    if(!root)
    return false;

    if(root->data==key)
    return true;

    if(key<root->data)
    return isPresent(root->left,key);

    return isPresent(root->right,key);
}

int main()
{
    bst b,*root = nullptr;
    root = b.insert(root,8);
    b.insert(root,3);
    b.insert(root,10);
    b.insert(root,1);
    b.insert(root,6);
    b.insert(root,4);
    b.insert(root,7);
    b.insert(root,14);
    b.insert(root,13);

    cout<<b.isPresent(root,3);
    return 0;
}