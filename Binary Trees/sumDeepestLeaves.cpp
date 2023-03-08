#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct tree{
    int val;
    tree *left,*right;

    tree(int val){
        this->val = val;
        this->left = this->right = nullptr;
    }
};

int deepestLeavesSum(tree *root){
    if(!root)
    return 0;

    vector<vector<int>> lv;

    queue<tree*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> temp;

        for(int i=0;i<size;i++){
            tree *node = q.front();
            temp.push_back(node->val);
            q.pop();

            if(node->left)
            q.push(node->left);

            if(node->right)
            q.push(node->right);
        }
        lv.push_back(temp);
    }

    int sum = 0;
    vector<int> ans = lv[lv.size()-1];

    for(int x : ans){
        sum+=x;
    }
}

int main(){
    tree *root = new tree(1);
    root->left = new tree(2);
    root->right = new tree(3);
    root->left->left = new tree(4);
    root->left->right = new tree(5);
    root->left->left->left = new tree(7);
    root->right->right = new tree(6);
    root->right->right->right = new tree(8);

    deepestLeavesSum(root);
    return 0;
}