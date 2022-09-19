#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;

struct tree{
    int data;
    tree *left,*right;

    tree(int data){
        this->data=data;
        this->right=this->left=NULL;
    }
};

//we must do horizontal order traversal, i.e BFS
//1.using maps and queues,Time Complexity : O(nlogn)
vector<int> topView1(tree *root){
    vector<int> ans;
    map<int,int> mp;
    queue<pair<tree*,int>> q;

    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<tree*,int> p = q.front();
        q.pop();

        tree *temp=p.first;
        int hd = p.second;

        if(mp.find(hd)==mp.end())
        mp[hd]=temp->data;

        if(temp->left)
        q.push(make_pair(temp->left,hd-1));
        if(temp->right)
        q.push(make_pair(temp->right,hd+1));
    }

    for(auto x:mp){
        ans.push_back(x.second);
    }
    return ans;
}

//2.Without hashing, using stack to store left and queue to store right
//Time Complexity : O(n);
void topView2(tree *root){
    stack<int> left;
    vector<int> right;
    queue<pair<tree*,int>> q;

    int hd=0,l=0,r=0;

    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<tree*,int> p = q.front();
        q.pop();

        tree *temp = p.first;
        hd = p.second;

        if(hd<l){
            left.push(temp->data);
            l = hd;
        }
        if(hd>r){
            right.push_back(temp->data);
            r = hd;
        }
        if(temp->left)
        q.push(make_pair(temp->left,hd-1));
        if(temp->right)
        q.push(make_pair(temp->right,hd+1));
    }
    while(!left.empty()){
        cout<<left.top()<<" ";
        left.pop();
    }

    cout<<root->data<<" ";
    for(auto x:right){
        cout<<x<<" ";
    }
}

int main()
{
    tree *root = new tree(10);
    root->left = new tree(20);
    root->right = new tree(30);
    root->left->left = new tree(40);
    root->left->right = new tree(60);

    root->right->left = new tree(90);
    root->right->right = new tree(100);
    /*          10
                / \
              20   30
             / \   / \
            40 60 90 100*/

    vector<int> ans1 = topView1(root); 
    for(auto x:ans1){
        cout<<x<<" ";
    }
    cout<<endl;
    topView2(root);
    return 0;
}