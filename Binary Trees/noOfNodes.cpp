#include<iostream>
#include<queue>
using namespace std;

struct tree{
    int value;
    tree *left,*right;

    tree(int value){
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

int countNodes(tree *root){
    if(!root)
    return 0;

    //use bfs to count nodes for a complete binary tree
    queue<tree*> q;
    q.push(root);
    vector<int> ans;

    while(!q.empty()){
        tree *temp = q.front();
        ans.push_back(temp->value);
        q.pop();

        if(temp->left)
        q.push(temp->left);

        if(temp->right)
        q.push(temp->right);
    }

    return ans.size();
}

int main(){
    tree *root = new tree(1);
    root->left = new tree(2);
    root->right = new tree(3);
    root->left->left = new tree(4);
    root->left->right = new tree(5);
    root->right->left = new tree(6);

    cout<<countNodes(root);
    return 0;
}