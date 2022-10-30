#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct btree{
    int data;
    btree *left,*right;

    btree(int data){
        this->data = data;
        this->right = this->left = nullptr;
    }
};  

//by help of inorder traversal of btree
void getVector(btree *root,vector<int>&helper){
    if(!root)   return;

    getVector(root->left,helper);
    helper.push_back(root->data);
    getVector(root->right,helper);
}

btree *makeBST(vector<int>&helper,int start,int end){
    //base case
    if(start>end)   return nullptr;

    //get middle element and making it root
    int mid = (start+end)/2;
    btree *newRoot = new btree(helper[mid]);

    //do the same for left and right subtrees
    newRoot->left = makeBST(helper,start,mid-1);
    newRoot->right = makeBST(helper,mid+1,end);

    return newRoot;
}

btree *convertToBST(btree *root){
    vector<int> helper;

    getVector(root,helper);

    sort(helper.begin(),helper.end());

    int n = helper.size();
    return makeBST(helper,0,n-1);
}

void inorder(btree *newRoot){
    if(!newRoot)    return;

    inorder(newRoot->left);
    cout<<newRoot->data<<" ";
    inorder(newRoot->right);
}

int main()
{
    btree *root = new btree(10);
    root->left = new btree(2);
    root->right = new btree(7);
    root->right->left = new btree(8);
    root->right->right = new btree(4);

    btree *newRoot = convertToBST(root);
    inorder(newRoot);
    return 0;
}