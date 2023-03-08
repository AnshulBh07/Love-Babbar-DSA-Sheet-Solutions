#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct tree{
    int val;
    tree *left,*right;

    tree(int val){
        this->val = val;
        this->left = this->right = nullptr;
    }
};

vector<double> averageOfLevels(tree *root){
    vector<double> ans;
    vector<vector<int>> levelv;

    queue<tree*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> temp;

        for(int i=0;i<size;i++){
            tree *node = q.front();
            temp.push_back(node->val);
            q.pop();

            if(node->left)
            q.push(node->left);

            if(node->right)
            q.push(node->right);
        }

        levelv.push_back(temp);
    }

    for(vector<int> v : levelv){
        cout<<"{";
        for(int x : v){
            cout<<x<<",";
        }
        cout<<"}";
    }

    double average;

    for(auto v : levelv){
        double levelsum = 0;
        for(int x : v){
            levelsum+=(double)x;
        }
        average = levelsum/(double)v.size();
        ans.push_back(average);
    }

    for(double x : ans){
        cout<<x<<",";
    }
}

int main(){
    tree *root = new tree(3);
    root->left = new tree(9);
    root->right = new tree(20);
    root->right->left = new tree(15);
    root->right->right = new tree(7);

    averageOfLevels(root);
    return 0;
}