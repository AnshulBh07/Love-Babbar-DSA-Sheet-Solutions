#include<iostream>
#include<queue>
using namespace std;

struct tree{
    int data;
    tree *left,*right;

    tree(int data){
        this->data=data;
        this->left=this->right=NULL;
    }
};

struct node{
    int value;
    node *next;

    node(int value){
        this->value=value;
        this->next=NULL;
    }
};

node *insert_beg(node *head,int value){
    node *newnode = new node(value);
    newnode->next=head;
    head = newnode;
    return head;
}

tree *convert(node *head){
    if(head==NULL)
    return nullptr;

    tree *root = new tree(head->value);
    head=head->next;

    queue<tree*> q;
    q.push(root);

    while(head!=NULL){

        tree *temp = q.front();
        q.pop();

        temp->left = new tree(head->value);
        q.push(temp->left);
        head=head->next;

        if(head!=NULL){
            temp->right = new tree(head->value);
            q.push(temp->right);
            head=head->next;
        }
    }
    return root;
}

//O(n)
void inOrder(tree *root){
    if(root==NULL)
    return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

//O(n)
void preOrder(tree *root){
    if(root==NULL)
    return;

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

//O(n)
void postOrder(tree *root){
    if(root==NULL)
    return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void display(node *head){
    if(head==NULL)
    return;

    node *temp=head;
    while(temp!=NULL){
        cout<<temp->value<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

int height(tree *root){
    if(root==NULL)
    return NULL;

    int ls = height(root->left);
    int rs = height(root->right);
    
    return max(ls,rs)+1;
}

int main()
{
    int n = 8;
    node *head = NULL;
    for(int i=n;i>0;i--){
        head = insert_beg(head,i);
    }
    display(head);
    tree *ans = convert(head);
    inOrder(ans);
    cout<<endl;
    preOrder(ans);
    cout<<endl;
    postOrder(ans);
    cout<<"Height : "<<height(ans);
    return 0;
}