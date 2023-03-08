#include<iostream>
using namespace std;

struct node{
    node *next;
    int value;

    node(int value){
        this->next = nullptr;
        this->value = value; 
    }
};

node* oddEvenList(node *head){
    if(!head)
    return nullptr;

    node *o,*e,*ehead;
    o = head;
    e = head->next;
    ehead = e;

    while(e && e->next){
        o->next = o->next->next;
        e->next = e->next->next;
        o = o->next;
        e = e->next;
    }
    o->next = ehead;
    return head;
}

void display(node *head){
    if(!head)
    return;

    node *temp = head;
    while(temp){
        cout<<temp->value<<"->";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);

    display(head);

    node *newhead = oddEvenList(head);
    display(newhead);
    return 0;
}