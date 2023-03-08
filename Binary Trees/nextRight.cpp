#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct tree{
    int val;
    tree *left,*right,*next;

    tree(int val){
        this->val = val;
        this->next = this->right = this->left = nullptr;
    }
};

vector<int> populateNext(tree *root){
    vector<int> ans;

    if(!root)
    return ans;

    queue<pair<tree*,int>> q;
    q.push({root,0});

    int curr = 0;

    while(!q.empty()){
        tree *temp = q.front().first;
        int level = q.front().second;
        if(curr!=level){
            ans.push_back(-1);
            curr++;
        }
        ans.push_back(temp->val);
        q.pop();

        if(temp->left)
        q.push({temp->left,level++});

        if(temp->right)
        q.push({temp->right,level++});
    }

    for(int x : ans){
        cout<<x<<" ";
    }
}

int main(){
    tree *root = new tree(1);
    root->left = new tree(2);
    root->right = new tree(3);
    root->left->left = new tree(4);
    root->left->right = new tree(5);
    root->right->left = new tree(6);
    root->right->right = new tree(7);

    populateNext(root);
    
    return 0;
}