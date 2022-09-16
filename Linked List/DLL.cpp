#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node *prev;

    node(){
        next=NULL;
        prev=NULL;
    }
};

void push(node *head,int value){
    node *newnode = new node();

    newnode->data=value;

    if(head==NULL)
    head=newnode;

    newnode->next=head;

    if(head!=NULL)
    head->prev=newnode;
    
    head=newnode;
}

void display(node *head){
    if(head==NULL)
    return;

    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    node *head = NULL;
    push(head,20);
    push(head,6);
    push(head,86);
    push(head,3);
    push(head,9);

    display(head);
}