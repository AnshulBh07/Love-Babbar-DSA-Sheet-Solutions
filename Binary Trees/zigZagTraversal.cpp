#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

struct tree{
    int data;
    tree *right,*left;

    tree(int data){
        this->data=data;
        this->right=this->left=nullptr;
    }
};

void zigZagTraversal(tree *root){
    if(root==nullptr)
    return;

    queue<tree*> q;
    vector<int> ans;
    int level = 0;

    q.push(root);
    while(!q.empty()){
        int s=q.size();
        vector<int> helper;

        while(s>0){
            tree *temp = q.front();
            q.pop();
            helper.push_back(temp->data);

            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
            s--;
        }

        if(level%2!=0){
            reverse(helper.begin(),helper.end());
            for(auto it:helper){
                ans.push_back(it);
            }
        }
        else{
            for(auto it:helper){
                ans.push_back(it);
            }
        }
        level++;
    }
    for(auto it:ans){
        cout<<it<<" ";
    }
}

int main()
{
    tree *root = new tree(7);
    root->left = new tree(9);
    root->right = new tree(7);
    root->left->left = new tree(8);
    root->left->right = new tree(8);
    root->left->left->left = new tree(10);
    root->left->left->right = new tree(9);
    root->right->left = new tree(6);

    zigZagTraversal(root);
    return 0;
}