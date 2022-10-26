#include<iostream>
using namespace std;

struct tree{
    int data;
    tree *left,*right;

    tree(int data){
        this->data = data;
        this->right = this->left = nullptr;
    }
};

void BTtoDLL(tree *root,tree *head){
    if(!root)
    return;

    static tree *prev = nullptr;

    BTtoDLL(root->left,head);

    //conversion
    if(!prev)
    head = root;
    else{
        root->left = prev;
        prev->right = root;
    }
    prev = root;

    BTtoDLL(root->right,head);
}

void print(tree *head){
    if(!head)
    return;

    while(head!=nullptr){
        cout<<head->data<<"->";
        head=head->right;
    }
}

int main()
{
    tree* root = new tree(10);
    root->left = new tree(12);
    root->right = new tree(15);
    root->left->left = new tree(25);
    root->left->right = new tree(30);
    root->right->left = new tree(36);
    tree *head = nullptr;
    BTtoDLL(root,head);
    print(head);
    return 0;
}