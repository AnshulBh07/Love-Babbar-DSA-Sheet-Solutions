#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct tree{
    int data;
    tree *right,*left;

    tree(int data){
        this->data=data;
        this->right=this->left=NULL;
    }
};

tree *convert(vector<int> v){
    if(v.size()==0)
    return nullptr;

    tree *root = new tree(v[0]);
    queue<tree*> q;
    q.push(root);

    for(int i=1;i<v.size();i++){
        tree *temp = q.front();
        q.pop();

        temp->left = new tree(v[i]);
        q.push(temp->left);
        i++;

        if(i<=v.size()){
            temp->right = new tree(v[i]);
            q.push(temp->right);
        }
    }
    return root;
}

void reverseLevelOrder(tree *root){
    if(root==NULL)
    return;

    vector<int> ans;

    queue<tree*> q;
    q.push(root);

    while(!q.empty()){
        tree *temp=q.front();
        ans.push_back(temp->data);
        q.pop();

        if(temp->left!=NULL)
        q.push(temp->left);

        if(temp->right!=NULL)
        q.push(temp->right);
    }

    reverse(ans.begin(),ans.end());
    for(int x:ans){
        cout<<x<<" ";
    }
}

int main()
{
    vector<int> v{1,6,3,5,8,10,2,7};
    tree *ans = convert(v);
    reverseLevelOrder(ans);
    return 0;
}