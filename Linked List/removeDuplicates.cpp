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

node *removeDuplicate1(node *head){
    if(head==NULL || head->next==NULL)
    return head;

    node *temp=head;

    while(temp->next!=NULL){
        if(temp->data==temp->next->data){
            temp->next=temp->next->next;
        }
        else
        temp=temp->next;
    }
    return head;
}

int main()
{
    node *head = newNode(2);
    head->next = newNode(2);
    head->next->next = newNode(2);
    head->next->next->next = newNode(2);
    head->next->next->next->next = newNode(2);

    node *ans = removeDuplicate1(head);
    display(ans);
    return 0;
}

