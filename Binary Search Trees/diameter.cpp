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

int height(tree *root){
    if(root==nullptr)
    return 0;

    return 1 + max(height(root->left),height(root->right));
}

int diameter(tree *root){
    if(root==nullptr)
    return 0;

    int d1=diameter(root->left);
    int d2=diameter(root->right);
    int h = height(root->left)+height(root->right)+1;

    return 1+max(h,max(d1,d2));
}

int main()
{
    vector<int> v{6,7,1,5,9,10,3,2,4};
    tree *ans = convert(v);
    cout<<diameter(ans);
    return 0;
}