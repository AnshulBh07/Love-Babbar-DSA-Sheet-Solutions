#include<iostream>
using namespace std;

struct node{
    int data;
    node *next,*prev;

    node(int data){
        this->data=data;
        this->next = this->prev = nullptr;
    }
};

void insertBeg(node **head_ref,int value){
    node *newnode = new node(value);
    newnode->prev = NULL;

    if(!(*head_ref)) newnode = (*head_ref);

    newnode->next = (*head_ref);

    if((*head_ref))
    (*head_ref)->prev = newnode;
    
    (*head_ref) = newnode;
}

void reverseDLL(node **head_ref)
{
    //Your code here
    node *temp1 = (*head_ref), *temp2 = temp1->next;
    temp1->next=nullptr;
    temp1->prev=temp2;
    while(temp2){
        temp2->prev = temp2->next;
        temp2->next=temp1;
        temp1=temp2;
        temp2=temp2->next;
    }
    (*head_ref) = temp1;
}


void display(node *head){
    if(!head) return;

    node *temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<"<->";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    node *head = NULL;
    insertBeg(&head,75);
    insertBeg(&head,122);
    insertBeg(&head,59);
    insertBeg(&head,196);

    display(head);
    reverseDLL(&head);
    display(head);
    return 0;
}