#include<iostream>
using namespace std;

struct tree{
    int data;
    tree *right,*left;

    tree(int data){
        this->data=data;
        this->right = this->left = nullptr;
    }
};

bool isIsomorphic(tree *root1,tree *root2){
    if(!root1 && !root2)
    return true;

    if(!root1 || !root2)
    return false;

    if(root1->data !=root2->data)
    return false;

    bool a = isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right);
    bool b = isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left);
    return a || b;
}

int main()
{
    tree *root1 = new tree(1);
    root1->left = new tree(2);
    root1->right = new tree(3);
    root1->left->left = new tree(4);

    tree *root2 = new tree(1);
    root2->left = new tree(3);
    root2->right = new tree(2);
    root2->right->right = new tree(4);

    cout<<isIsomorphic(root1,root2);
    return 0;
}