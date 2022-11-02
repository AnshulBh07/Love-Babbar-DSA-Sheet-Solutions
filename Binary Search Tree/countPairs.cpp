#include<iostream>
#include<vector>
using namespace std;

struct bst{
    int data;
    bst *right,*left;

    bst(int data){
        this->data = data;
        this->right = this->left = nullptr;
    }
};

bst *insert(bst *root,int val){
    if(!root)   
    return new bst(val);

    if(val > root->data)
    root->right = insert(root->right,val);
    else
    root->left = insert(root->left,val);

    return root;
}

//store bst in vectors
void storeBST(bst *root,vector<int>&v){
    if(!root)   return;

    storeBST(root->left,v);
    v.push_back(root->data);
    storeBST(root->right,v);
}

int countPairs(bst *root1,bst *root2,int k){
    if(!root1 || !root2)
    return 0;

    vector<int> bst1,bst2;
    storeBST(root1,bst1);
    storeBST(root2,bst2);

    //compare elements of both
    int n = bst1.size(),m=bst2.size(); 
    int i=0,j=m-1;
    int sum,count=0;

    while(i<n && j>=0){
        sum = bst1[i] + bst2[j];
        if(sum==k){
            count++;
            i++;
            j--;
        }
        else if(sum>k)
        j--;
        else
        i++;
    }
    return count;
}

int main()
{
    bst *root1 = new bst(5);
    insert(root1,3);
    insert(root1,7);
    insert(root1,2);
    insert(root1,4);
    insert(root1,6);
    insert(root1,8);

    bst *root2 = new bst(10);
    insert(root2,6);
    insert(root2,15);
    insert(root2,3);
    insert(root2,8);
    insert(root2,11);
    insert(root2,18);

    cout<<countPairs(root1,root2,16);
    return 0;
}