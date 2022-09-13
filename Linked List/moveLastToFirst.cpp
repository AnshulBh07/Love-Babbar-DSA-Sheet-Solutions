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

void display(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node *moveLast2First(node *head){
    if(head==NULL)
    return head;

    node *curr=head;
    while(curr->next->next!=NULL){
        curr=curr->next;
    }
    curr->next->next=head;
    head=curr->next;
    curr->next=NULL;
    return head;
}

int main()
{
    node *head = newNode(50);
    head->next = newNode(10);
    head->next->next = newNode(15);
    head->next->next->next = newNode(20);
    head->next->next->next->next = newNode(35);

    node *ans = moveLast2First(head);
    display(ans);
    return 0;
}

