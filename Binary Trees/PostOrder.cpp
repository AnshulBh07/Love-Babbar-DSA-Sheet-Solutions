//important as a little different 
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

void PostOrder(tree* root){
    if(!root)
    return;

    stack<tree*> s;
    s.push(root);

    stack<int> output;
    tree *curr;

    while(!s.empty()){
        curr = s.top();
        s.pop();

        output.push(curr->data);

        if(curr->left)
            s.push(curr->left);

        if(curr->right)
            s.push(curr->right);
    }

    while(!output.empty()){
        cout<<output.top()<<"->";
        output.pop();
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

    PostOrder(root);
    return 0;
}