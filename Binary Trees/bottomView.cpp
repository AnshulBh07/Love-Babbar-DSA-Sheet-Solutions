#include<iostream>
#include<queue>
#include<map>
using namespace std;

struct tree{
    int data;
    tree *right,*left;

    tree(int data){
        this->data=data;
        this->right=this->left=nullptr;
    }
};


//using tree map and using level order traversal (queues).
//Time complexity : O(n*logn)
void bottomView1(tree *root){
    if(root==nullptr)
    return;

    map<int,int> mp;
    queue<pair<tree*,int>> q;

    int hd;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<tree*,int> p = q.front();
        q.pop();

        tree *temp = p.first;
        hd = p.second;

        mp[hd] = temp->data;

        if(temp->left)
        q.push(make_pair(temp->left,hd-1));
        if(temp->right)
        q.push(make_pair(temp->right,hd+1));
    }

    for(auto it:mp){
        cout<<it.second<<" ";
    }
}


//using hashmap with recursion i.e. dfs or vertical order traversal 
//Time Complexity : O(n)
//the hashmap contains hd as key and a pair of height and data

int main()
{
    tree *root = new tree(20);
    root->left = new tree(8);
    root->right = new tree(22);
    root->left->left = new tree(5);
    root->left->right = new tree(3);
    root->left->right->left = new tree(10);
    root->left->right->right = new tree(14);
    root->right->left = new tree(4);
    root->right->right = new tree(25);

                        /*20
                         / \
                        8  22
                       / \ / \
                      5  3 10 14
                    /\
                   4 25*/
    bottomView1(root);
    return 0;
}