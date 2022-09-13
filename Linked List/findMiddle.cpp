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

node *findMiddle(node *head){
    int count=0;
        node* temp;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        temp=head;
        if(count%2==0){
            for(int i=0;i<count/2;i++)
                temp=temp->next;
        }
        else{
            for(int i=0;i<count/2;i++)
                temp=temp->next;
        }
        return temp;
}

int main()
{
    node *head = newNode(5);
    head->next = newNode(4);
    head->next->next = newNode(10);
    head->next->next->next = newNode(9);
    head->next->next->next->next = newNode(8);
    head->next->next->next->next->next = newNode(2);

    display(head);
    node *ans = findMiddle(head);
    display(ans);
    return 0;
}