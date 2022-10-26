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

//printing inorder using a stack, Time complexity : O(n) and space complexity O(n)
void printInorder(tree *root){
    if(!root)
    return;

    stack<tree*> st;
    tree *curr = root;

    while(curr!=nullptr || !st.empty()){
        while(curr!=nullptr){
            st.push(curr);
            curr=curr->left;
        }

        curr = st.top();
        st.pop();

        cout<<curr->data<<" ";

        curr = curr->right;
    }
}

int main()
{
    tree *root        = new tree(1);
    root->left        = new tree(2);
    root->right       = new tree(3);
    root->left->left  = new tree(4);
    root->left->right = new tree(5);

    printInorder(root);
    return 0;
}