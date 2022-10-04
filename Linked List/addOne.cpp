#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;

    node(int data){
        this->data=data;
        this->next=nullptr;
    }
};

node *reverseList(node *head){
    if(!head)
    return head;

    node *curr = head,*after=nullptr,*prev=nullptr;
    while(curr){
        after = curr->next;
        curr->next = prev;
        prev = curr;
        curr = after;
    }
    return prev;
}

node* addOne(node *head){
    node *head1 = reverseList(head);

    node *curr = head1;
    node *prev = nullptr;
    node *newHead;

    int carry = 1;
    int x;
    while(curr && carry){
        x = curr->data;
        x+=1;
        carry = x/10;
        if(carry){
            x = x%10;
        }
        curr->data = x;
        prev = curr;
        curr = curr->next;
    }
    //in case of a carry existing even after the complete list has been traversed e.g. 999
    if(carry){
        node *temp = new node(carry);
        prev->next = temp;
    }

    newHead = reverseList(head1);
    return newHead;
}

void display(node *head){
    if(!head) return;

    node *temp=head;
    while(temp){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}

int main()
{
    node *head = new node(4);
    head->next = new node(5);
    head->next->next = new node(9);

    addOne(head);
    display(head);
    return 0;
}