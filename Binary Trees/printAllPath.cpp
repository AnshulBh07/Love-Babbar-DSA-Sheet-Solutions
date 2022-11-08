#include<iostream>
#include<vector>
using namespace std;

struct tree{
    int data;
    tree *left,*right;

    tree(int data){
        this->data = data;
        this->right = this->left = nullptr;
    }
};

void getPath(vector<string>&ans,tree *root,string t){
    //base case
    if(!root)
    return;

    if(!root->left && !root->right)
    {
        ans.push_back(t);
        return;
    }

    if(root->left)
    getPath(ans,root->left,t + "->" + to_string(root->left->data));
    if(root->right)
    getPath(ans,root->right,t+"->"+to_string(root->right->data)); 
}

int main()
{
    tree *root = new tree(1);
    root->left = new tree(2);
    root->left = new tree(3);
    root->left->right = new tree(4);

    vector<string> ans; 
    getPath(ans,root,to_string(root->data));
    for(auto x:ans)
        cout<<x<<" ";
    return 0;
}