#include <iostream>
#include<map>
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

node *removeDuplicate(node *head){
    map<int,int> helper;
    node *ans = newNode(-1);

    node*temp=head;
    while(temp->next!=NULL){
        helper[temp->data]++;
        temp=temp->next;
    }

    temp=head;
    for(auto it:helper){
        temp->data=it.first;
        temp=temp->next;
    }
    return head;
}

int main()
{
    node *head = newNode(10);
    head->next = newNode(5);
    head->next->next = newNode(4);
    head->next->next->next = newNode(5);
    head->next->next->next->next = newNode(2);

    node *ans = removeDuplicate(head);
    display(ans);
    return 0;
}

