#include <iostream>
#include<vector>
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

void display(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node *segregate(node *head){
    int c0=0,c1=0,c2=0;
    node *temp=head;
    while(temp!=NULL){
        if(temp->data==0)
        c0++;
        else if(temp->data==1)
        c1++;
        else
        c2++;
        temp=temp->next;
    }

    node *curr=head;
    while(c0--){
        curr->data=0;
        curr=curr->next;
    }
    
    while(c1--){
        curr->data=1;
        curr=curr->next;
    }
    
    while(c2--){
        curr->data=2;
        curr=curr->next;
    }
    return head;
}

int main()
{
    node *head = newNode(2);
    head->next = newNode(1);
    head->next->next = newNode(2);
    head->next->next->next = newNode(1);
    head->next->next->next->next = newNode(0);
    head->next->next->next->next->next = newNode(0);

    display(head);
    segregate(head);
    display(head);
    return 0;
}