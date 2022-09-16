#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

node *newNode(int key)
{
    node *temp = new node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}

node *deleteCLL(node *head,int k){
    if(head == NULL)
    return head;

    node *curr=head->next,*prev;
    while(curr->data!=k){
        prev=curr;
        curr=curr->next;
    }

    if(curr==head){
        head=prev;
    }
    prev->next=curr->next;
    curr->next=NULL;
    return head;
}

void display(node *head)
{
    node *temp=head;
    if(head!=NULL){
        do{
            cout<<temp->data<<"->";
            temp=temp->next;
        }while(temp!=head);
    }
    cout<<endl;
}

int main()
{
    node *head = newNode(5);
    head->next = newNode(4);
    head->next->next = newNode(10);
    head->next->next->next = newNode(9);
    head->next->next->next->next = newNode(8);
    head->next->next->next->next->next = newNode(2);
    head->next->next->next->next->next=head;

    display(head);

    int k;
    cout<<"Enter data to be deleted : ";
    cin>>k;
    
    node *ans = deleteCLL(head,k);
    display(ans);
    return 0;
}