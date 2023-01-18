#include<iostream>
#include<stack>
using namespace std;

struct tree{
    int data;
    tree *left,*right;

    tree(int data){
        this->data = data;
        this->left = this->right = nullptr;
    }
};

void PreOrder(tree *root){
    if(!root)
    return;

    stack<tree*> s;
    tree *curr = root;

    while(!s.empty() || curr){
        if(curr){
            cout<<curr->data<<"->";
            s.push(curr);
            curr=curr->left;
        }
        else{
            curr = s.top();
            s.pop();
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

    PreOrder(root);
    return 0;
}