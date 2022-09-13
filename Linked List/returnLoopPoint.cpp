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

node *detectLooppoint(node *head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }

    node *slow=head,*fast=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast)
        break;
    }
    slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}

int main()
{
    node *head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    head->next->next->next->next->next=head->next->next;

    node *ans = detectLooppoint(head);
    if(ans==NULL){
        cout<<"Loop doesn't exist!\n";
    }
    else{
        cout<<"loop exists at node "<<ans->data;
    }
    return 0;
}

