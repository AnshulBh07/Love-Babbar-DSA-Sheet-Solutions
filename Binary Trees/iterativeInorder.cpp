#include<iostream>
#include<stack>
using namespace std;

struct tree{
    int data;
    tree *left,*right;

    tree(int data){
        this->data = data;
        this->right = this->left = nullptr;
    }
};

void Inorder(tree *root){
    if(!root)
    return;

    stack<tree*> s;
    tree *curr = root;

    while(!s.empty() || curr!=nullptr){
        if(curr){
            s.push(curr);
            curr=curr->left;
        }
        else{
            curr = s.top();
            s.pop();
            cout<<curr->data<<"->";
            curr=curr->right;
        }
    }
}

int main(){
    tree *root = new tree(8);
    root->right = new tree(7);
    root->left = new tree(10);
    root->left->left = new tree(4);
    root->left->left->right = new tree(1);
    root->right->left = new tree(6);
    root->right->right = new tree(5);
    root->right->left->left = new tree(9);

    Inorder(root);
    return 0;
}