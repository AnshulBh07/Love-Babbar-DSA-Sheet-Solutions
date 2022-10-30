//debug it
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

node *reverse(node *head){
    if(!head)   return head;

    node *curr=head,*prev = nullptr,*after = nullptr;

    while(curr){
        after = curr->next;
        curr->next = prev;
        prev = curr;
        curr = after;
    }
    return prev;
}

node *add2LL(node *head1,node *head2){
    if(!head1)  return head2;
    if(!head2)  return head1;

    node *head3 = new node(0);

    node *newhead1 = reverse(head1);
    node *newhead2 = reverse(head2);

    int carry=1,sum;
    node *curr1=newhead1,*curr2=newhead2;
    node *curr3 = head3;

    while(curr1 || curr2){
        sum=0;
        if(curr1){
            sum+=curr1->data;
            curr1=curr1->next;
        }
        if(curr2){
            sum+=curr2->data;
            curr2=curr2->next;
        }
        sum+=carry;

        carry = sum/10;
        if(carry)
            sum = sum%10;
        
        curr3->next = new node(sum);
        curr3=curr3->next;
    }

    node *newhead3 = reverse(head3);
    return newhead3->next;
}

void display(node *head){
    if(!head)   return ;

    node *temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{
    node *head1 = new node(3);
    head1->next = new node(4);
    head1->next->next = new node(2);

    node *head2 = new node(4);
    head2->next = new node(6);
    head2->next->next = new node(5);

    node *head3 = add2LL(head1,head2);
    display(head3);
    return 0;
}