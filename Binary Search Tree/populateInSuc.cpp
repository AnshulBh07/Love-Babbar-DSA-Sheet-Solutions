#include<iostream>
#include<vector>
using namespace std;

struct bst{
    int data;
    bst *right,*left;
    bst *next;

    bst(int data){
        this->data = data;
        this->right = this->left = nullptr;
        this->next = nullptr;
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

void inorder(bst *root,vector<bst*> &ans){
    if(!root) return;

    inorder(root->left,ans);
    ans.push_back(root);
    inorder(root->right,ans);
}

vector<bst *> populateNext(bst *root,vector<bst*>&ans){
    if(!root)   return ans;

    inorder(root,ans);

    for(int i=0;i<ans.size();i++){
        ans[i]->next = ans[i+1]; 
    }

    for(bst *x :ans){
        cout<<x->data<<"->"<<x->next->data<<" ";
    }
}

int main()
{
    bst *root = new bst(3);
    insert(root,8);
    insert(root,10);
    insert(root,12);

    vector<bst *> ans;
    populateNext(root,ans);
    return 0;
}