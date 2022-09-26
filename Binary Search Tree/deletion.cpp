#include<iostream>
using namespace std;

class bst{
    public :
    int data;
    bst *right,*left;

    bst(){}

    bst(int data){
        this->data= data;
        this->right = this->left = nullptr;
    }

    bst *insert(bst *root,int data);
    bst *deleteNode(bst *root,int val);
    int minValue(bst* root);
};

bst* bst :: insert(bst *root,int data){
    if(!root)
    return new bst(data);

    if(data<root->data)
    return insert(root->left,data);
    else if(data<root->data)
    return insert(root->right,data);

    return root;
}

/*while deleting a node there are three cases
1. the node to be deleted is a leaf node
2. the node to be deleted is a node with only one child.
3. the node to be deleted has two children.
third case is the complicated one where we have two choices ie. either we can replace node by biggest 
element from left child or smallest element from right side,
we know that the inorder traversal of a bst gives a sorted array, i.e. we can replace it with it's
inordere predecessor or inorder successor. Lets just use successor */

//function to find inorder successor 
int bst :: minValue(bst *root){
    int minv = root->data;
    while(root->left!=nullptr){
        minv = root->left->data;
        root=root->left;
    }
    return minv;
}

bst* bst :: deleteNode(bst *root,int val){
    if(!root)
    return root;

    if(val<root->data)
    root->left = deleteNode(root->left,val);
    else if(val>root->data)
    root->right = deleteNode(root->right,val);

    else{
        if(root->left==nullptr)
        return root->right;

        else if(root->right == nullptr)
        return root->left;

        root->data = minValue(root->right);

        root->right = deleteNode(root->right,root->data);
    }

    return root;
}

void inOrder(bst *root){
    if(root==nullptr)
    return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main()
{
    bst b, *root = NULL;
    root = b.insert(root, 50);
    b.insert(root, 30);
    b.insert(root, 20);
    b.insert(root, 40);
    b.insert(root, 70);
    b.insert(root, 60);
    b.insert(root, 80);

    inOrder(root);
    cout<<endl;
    b.deleteNode(root,20);
    inOrder(root);
    return 0;
}