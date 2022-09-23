#include<iostream>
#include<queue>
#include<vector>
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

tree *convert(vector<int>&v){
    if(v.size()==0)
    return nullptr;

    queue<tree*> q;
    tree *root = new tree(v[0]);
    q.push(root);

    for(int i=1;i<v.size();i++){
        tree *temp = q.front();
        q.pop();

        temp->left = new tree(v[i]);
        q.push(temp->left);
        i++;

        if(i<=v.size())
        {
            temp->right = new tree(v[i]);
            q.push(temp->right);
        }
    }
    return root;
}

void leftView(tree *root,vector<int>&helper1,int level){
    if(root==nullptr)
    return;

    if(level==helper1.size())
    helper1.push_back(root->data);

    leftView(root->left,helper1,level+1);
    leftView(root->right,helper1,level+1);
}

void rightView(tree *root,vector<int>&helper2,int level){
    if(root==nullptr)
    return;

    if(level==helper2.size())
    helper2.push_back(root->data);

    rightView(root->right,helper2,level+1);
    rightView(root->left,helper2,level+1);
}

int main(){
    vector<int> v{7,5,8,1,2,4,6,9};
    tree *ans = convert(v);
    vector<int> helper1,helper2,helper3;
    int level = 0;

    leftView(ans,helper1,level);
    for(auto x:helper1){
        cout<<x<<" ";
    }
    cout<<endl;

    rightView(ans,helper2,0);
    for(auto x:helper2){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}