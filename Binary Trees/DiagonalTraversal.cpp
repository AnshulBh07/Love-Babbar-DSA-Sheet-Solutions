#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct tree{
    int data;
    tree *left,*right;

    tree(int data){
        this->data=data;
        this->right=this->left=nullptr;
    }
};

//O(n) - we are traversing each node once only
//Space complexity : O(n) - we are using a queue to store nodes 
void diagonalTraversal1(tree *root){
    vector<int> ans;
    queue<tree*> q;

    q.push(root);
    while(!q.empty()){
        tree *temp = q.front();
        q.pop();

        while(temp){
            if(temp->left)
            q.push(temp->left);
            ans.push_back(temp->data);
            temp=temp->right;
        }
    }
    for(auto it:ans){
        cout<<it<<" ";
    }
}

int main()
{
    tree *root= new tree(8);
    root->right = new tree(10);
    root->left = new tree(3);
    root->left->left= new tree(1);
    root->left->right = new tree(6);
    root->left->right->left=new tree(4);
    
    root->left->right->right=new tree(7);
    root->right->right=new tree(5);
    root->right->right->left= new tree(2);

    diagonalTraversal1(root);
    return 0;
}