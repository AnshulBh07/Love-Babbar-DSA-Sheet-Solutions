#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;

    node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

int length(node *head){
    if(!head) return 0;

    int len=0;
    node *temp = head;
    while(temp){
        len++;
        temp=temp->next;
    }
    return len;
}

int intersectionPoint(node *head1,node *head2){
    if(!head1 || !head2) return 0;

    int l1 = length(head1);
    int l2 = length(head2);

    int diff = abs(l1-l2);
    node *temp1 = head1,*temp2=head2;
    if(l1>l2){
        while(diff--)
        temp1=temp1->next;
    }
    else if(l2>l1){
        while(diff--)
        temp2=temp2->next;
    }

    while(temp1!=temp2){
        temp1=temp1->next;
        temp2=temp2->next;
    }

    return temp1->data;
}

void display(node *head){
    if(!head) return;

    node *temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    node *head1 = new node(3);
    head1->next = new node(6);
    head1->next->next = new node(9);
    head1->next->next->next = new node(15);
    head1->next->next->next->next = new node(30);

    node *head2 = new node(10);
    head2->next = head1->next->next->next;
    head2->next->next = head1->next->next->next->next;
    display(head1);
    display(head2);

    cout<<intersectionPoint(head1,head2);
    return 0;
}