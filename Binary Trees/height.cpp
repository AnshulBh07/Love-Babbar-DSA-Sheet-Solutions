#include<iostream>
#include<queue>
using namespace std;

struct tree{
    int data;
    tree *right, *left;

    tree(int data){
        this->data = data;
        this->right = this->left = nullptr;
    }
};

/*  Recursive solution
O(n),O(n)
int height(tree *root){
    if(!root)   return 0;

    int ls = height(root->left);
    int rs = height(root->right);

    return max(ls,rs)+1; 
}*/

//iterative with same time and space complexity using level order traversal
int height(tree *root){
    if(!root)   return 0;

    queue<tree*> q;
    q.push(root);
    q.push(NULL);
    //whenever a null is encountered we will increment the height, it means that we move down 
    //one level
    int depth;
    tree *temp;

    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp==NULL)
        depth++;

        if(temp!=NULL){
            if(temp->left)
            q.push(temp->left);

            if(temp->right)
            q.push(temp->right);
        }

        //if queue still has elements 
        else if(!q.empty())
        q.push(NULL);
    }
    return depth;
}

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

    cout<<height(root);
    return 0;
}