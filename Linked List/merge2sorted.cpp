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

node *merge2lists(node *list1,node *list2){
    node *t1 = list1, *t2 = list2;

    if(!t1) return list2;
    if(!t2) return list1;

    node *dummy = new node(-1);
    node *temp = dummy;

    while(t1 && t2){
        if(t1->data <= t2->data){
            temp->next = t1;
            t1 = t1->next;
        }
        else{
            temp->next = t2;
            t2 = t2->next;
        }
        temp = temp->next;
    }

    //if either of two lists remain
    if(t1){
        while(t1){
            temp->next = t1;
            t1 = t1->next;
            temp=temp->next;
        }
    }
    if(t2){
        while(t2){
            temp->next = t2;
            t2 = t2->next;
            temp=temp->next;
        }
    }
    return dummy->next;
}

void print(node *head){
    if(!head)   return;

    node *temp = head;
    while(temp){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}

int main()
{
    node *list1 = new node(1);
    list1->next = new node(2);
    list1->next->next = new node(4);

    node *list2 = new node(1);
    list2->next = new node(3);
    list2->next->next = new node(4);

    node *ans = merge2lists(list1,list2);
    print(ans);
    return 0;
}