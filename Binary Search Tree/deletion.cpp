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
    bst *minValue(bst* root);
};

bst* bst :: insert(bst *root,int data){
    if(!root)
    return new bst(data);

    if(data<root->data)
    root->left = insert(root->left,data);
    else if(data>root->data)
    root->right = insert(root->right,data);

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
bst *bst :: minValue(bst *root){
    bst *currnode = root;

    while(currnode && currnode->left!=nullptr){
        currnode=currnode->left;
    }
    return currnode;
}

bst* bst :: deleteNode(bst *root,int val){
    if(!root)
    return root;

    if(root->data<val)
    root->right = deleteNode(root->right,val);

    else if(root->data>val)
    root->left = deleteNode(root->left,val);

    else{
        //the node is to be deleted has no child
        if(!root->left && !root->right){
            return nullptr;
        }

        //if the node to be deleted has one child
        else if(!root->left){
            bst *temp = root->right;
            free(root);
            return temp;
        }
        else if(!root->right){
            bst *temp = root->left;
            free(root);
            return temp;
        }

        //if the node has two children
        bst *temp = minValue(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right,temp->data);
    }
    return root;
}

void inOrder(bst *root){
    if(!root)
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

    cout<<"Inorder traversal before deeltion : ";
    inOrder(root);
    cout<<endl;
    root = b.deleteNode(root,20);
    cout<<"Inorder traversal after deletion : ";
    inOrder(root);
    return 0;
}