#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct bst{
    int data;
    bst *right,*left;

    bst(int data){
        this->data = data;
        this->left = this->right = nullptr;
    }
};

bst *insert(bst *root,int val){
    if(!root)
    return new bst(val);

    if(val > root->data)
    root->right = insert(root->right,val);
    else
    root->left = insert(root->left,val);

    return root;
}

//storing bst into vetcors using inorder traversals
void storeBST(bst *root,vector<int>&v){
    if(!root)   return;

    storeBST(root->left,v);
    v.push_back(root->data);
    storeBST(root->right,v);
}

//converting final vector to bst
bst *convertToBST(vector<int>&finalv,int start,int end){
    //base case
    if(start>end)
    return nullptr;

    int mid = (start+end)/2;
    bst *newRoot = new bst(finalv[mid]);

    //recur for left and right subtrees
    newRoot->left = convertToBST(finalv,start,mid-1);
    newRoot->right = convertToBST(finalv,mid+1,end);

    return newRoot;
}

bst *mergeBST(bst *root1,bst *root2){
    if(!root1)  return root2;
    if(!root2)  return root1;

    vector<int> helper1,helper2;

    storeBST(root1,helper1);
    storeBST(root2,helper2);

    vector<int> finalv;
    for(int i=0;i<helper1.size();i++)
    finalv.push_back(helper1[i]);

    for(int i=0;i<helper2.size();i++)
    finalv.push_back(helper2[i]);

    sort(finalv.begin(),finalv.end());

    return convertToBST(finalv,0,finalv.size()-1);
}

void inorder(bst *root){
    if(!root)   return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{   
    bst *root1 = new bst(1);
    insert(root1,2);
    insert(root1,3);
    insert(root1,4);
    insert(root1,5);

    bst *root2 = new bst(6);
    insert(root2,7);
    insert(root2,8);
    insert(root2,9);

    bst *newRoot = mergeBST(root1,root2);
    inorder(newRoot);
    return 0;
}