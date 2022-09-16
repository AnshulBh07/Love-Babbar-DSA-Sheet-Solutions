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

void levelOrder(tree *root){
    if(root==NULL)
    return;

    queue<tree*> q;
    q.push(root);

    while(!q.empty()){
        tree *temp = q.front();
        cout<<temp->data<<" ";
        q.pop();

        if(temp->left!=NULL)
        q.push(temp->left);

        if(temp->right!=NULL)
        q.push(temp->right);
    }
}

int main()
{
    vector<int> v{6,7,1,5,9,10,3,2,4};
    tree *ans = convert(v);
    levelOrder(ans);
    return 0;
}