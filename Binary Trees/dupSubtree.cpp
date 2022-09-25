#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct tree{
    int data;
    tree *right,*left;

    tree(int data){
        this->data = data;
        this->right = this->left = nullptr;
    }
};

unordered_map<string,int> mp;

string solve(tree *root){
    if(!root)
    return "$";

    string s = " ";
    //if the root is leaf node push root in string and return 
    if(!root->right && !root->left){
    s = s + to_string(root->data);
    return s;
    }

    s+=to_string(root->data);
    s+=solve(root->left);
    s+=solve(root->right);
    mp[s]++;
    return s;
}

void printDups(tree *root){
    solve(root);
    for(auto x:mp){
        if(x.second>=2)
        cout<<x.first<<" ";
    }
}

int main()
{
    tree *root= new tree(1);
    root->left = new tree(2);
    root->right = new tree(3);
    root->left->left = new tree(4);
    root->right->left = new tree(2);
    root->right->left->left = new tree(4);
    root->right->right = new tree(4);

    printDups(root);
    return 0;
}