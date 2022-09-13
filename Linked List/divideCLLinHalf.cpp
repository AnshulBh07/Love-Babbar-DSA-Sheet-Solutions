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

void splitList(node *head,node **head1,node **head2){
    node *slow=head,*fast=head;
    *head1 = head;
    if(head==NULL || head->next==NULL)
    return;

    while(fast->next!=head && fast->next->next!=head){
        fast=fast->next->next;
        slow=slow->next;
    }

    *head2 = slow->next;
    slow->next=head;

    if(fast->next->next==head){
        fast->next->next=*head2;
    }
    else{
        fast->next=*head2;
    }
}

void display(node *head)
{
    while (head != NULL)
    {
        cout << head->data<<"->";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    node *head = newNode(5);
    head->next = newNode(4);
    head->next->next = newNode(10);
    head->next->next->next = newNode(9);
    head->next->next->next->next = newNode(8);
    head->next->next->next->next->next = newNode(2);
    head->next->next->next->next->next->next=head;

    node *head2 = NULL,*head1 = NULL;
    splitList(head,&head1,&head2);
    display(head1);
    display(head2);
    return 0;
}