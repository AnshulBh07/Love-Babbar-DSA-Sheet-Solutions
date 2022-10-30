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

//changing the structure of bst while inorder traversal
void inorder(bst *root,bst *&prev){
    if(!root)   return;

    inorder(root->left,prev);
    prev->left = nullptr;
    prev->right = root;
    prev = root;
    inorder(root->right,prev);
}

bst* flattenBST(bst *root){
    //using a dummy node to start our LL
    bst *dummy = new bst(-1);

    bst *prev = dummy;

    inorder(root,prev);

    bst *head = dummy->right;
    dummy->right = nullptr;
    delete dummy;

    return head;
}

void print(bst *head){
    if(!head)   return;

    while(head){
        cout<<head->data<<"->";
        head=head->right;
    }
}

int main()
{
    bst *root = new bst(3);
    insert(root,7);
    insert(root,5);
    insert(root,2);
    insert(root,4);
    insert(root,6);
    insert(root,8);

    bst *head = flattenBST(root);
    print(head);
    return 0;
}