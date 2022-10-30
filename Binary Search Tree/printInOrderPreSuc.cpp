//leaf node waale edge case par socho
#include<iostream>
#include<vector>
using namespace std;

struct bst{
    int data;
    bst *left,*right;

    bst(int data){
        this->data = data;
        this->left = this->right = nullptr;
    }
};

bst *insertNode(bst *root,int key){
    if(!root)
    return new bst(key);

    if(root->data<key)
    root->right = insertNode(root->right,key);
    else if(root->data>key)
    root->left = insertNode(root->left,key);

    return root;
}

bst *findnode(bst *root,int val){
    if(!root)
    return root;

    if(root->data == val)
    return root;

    if(val>root->data)
        return findnode(root->right,val);
    else
        return findnode(root->left,val); 
}

void findInorderPreSuc(bst *root,int val){
    if(!root)
    return;

    bst *keynode = findnode(root,val);

    vector<int> ans;
    if(keynode){
        //for in order successor
        //if keynode has a right subtree
        if(keynode->right){
            bst *temp = keynode->right;
            while(temp->left)
                temp=temp->left;
            ans.push_back(temp->data);
        }else{
            ans.push_back(-1);
        }

        if(keynode->left){
            bst *temp = keynode->left;
            while(temp->right)
                temp=temp->right;
            ans.push_back(temp->data);
        }else{
            ans.push_back(-1);
        }
    }

    for(auto x:ans)
    cout<<x<<" ";
}

void inorder(bst *root){
    if(!root)   return;

    inorder(root->left);
    cout<<root->data<<"->";
    inorder(root->right);
}

int main()
{
    bst* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    inorder(root);
    cout<<endl;
    int val = 60;
    findInorderPreSuc(root,val);
    return 0;
}