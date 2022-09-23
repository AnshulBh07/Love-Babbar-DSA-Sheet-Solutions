#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct tree{
    int data;
    tree *left,*right;

    tree(int data){
        this->data=data;
        this->left=this->right=NULL;
    }
};

tree *convert(vector<int> v){
    if(v.size()==0)
    return nullptr;

    tree *root= new tree(v[0]);

    queue<tree*> q;
    q.push(root);

    for(int i=1;i<v.size();i++){
        tree *temp = q.front();
        q.pop();

        temp->left = new tree(v[i]);
        q.push(temp->left);
        i++;

        if(i!=v.size()){
            temp->right = new tree(v[i]);
            q.push(temp->right);
        }
    }
    return root;
}

void mirrorTree(tree *root){
    if(root==nullptr)
    return;

    tree *temp = root->left;
    root->left = root->right;
    root->right = temp;

    if(root->left!=nullptr)
    mirrorTree(root->left);

    if(root->right!=nullptr)
    mirrorTree(root->right);
}

void inOrder(tree *root){
    if(root==nullptr)
    return;

    inOrder(root->left);
    cout<<root->left<<" ";
    inOrder(root->right);
}

int main()
{
    vector<int> v{6,7,1,5,9,10,3,2,4};
    tree *ans = convert(v);
    inOrder(ans);
    mirrorTree(ans);
    inOrder(ans);
    return 0;
}