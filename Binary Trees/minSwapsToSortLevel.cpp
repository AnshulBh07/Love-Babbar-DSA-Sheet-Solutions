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

void printLevel(tree *root){
    if(!root)
    return;

    vector<vector<int>> v; //vector storing nodes as per level

    //using bfs 
    queue<pair<tree*,int>> q; //q storing nodes with their levels
    q.push({root,1});

    while(!q.empty()){
        tree *temp = q.front().first;
        int level = q.front().second;
        v[level].push_back(temp->value);
        q.pop();

        if(temp->left)
        q.push({temp->left,level+1});

        if(temp->right)
        q.push({temp->right,level+1});
    }

    for(vector<int> ans : v){
        cout<<"{";
        for(int x : ans){
            cout<<x<<",";
        }
        cout<<"}";
    }
}

int main(){
    tree *root = new tree(1);
    root->left = new tree(4);
    root->right = new tree(3);
    root->left->left = new tree(7);
    root->left->right = new tree(6);
    root->right->left = new tree(8);
    root->right->right = new tree(5);
    root->right->left->left = new tree(9);
    root->right->right->left = new tree(10);

    printLevel(root);
    return 0;
}