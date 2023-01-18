//Space Complexity : O(max(m,n))
//Time Complexity : O(max(m,n))
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

//function to reverse a list
node *reverseList(node *head){
    if(!head)   return head;

    node *curr = head;
    node *prev = nullptr,*after = nullptr;

    while(curr){
        after = curr->next;
        curr->next = prev;
        prev = curr;
        curr = after;
    }
    return head;
}

//add both the lists and store it in a third list
node *addBothLists(node *l1,node *l2){
    if(!l1) return l2;
    if(!l2) return l1;

    node *head1 = reverseList(l1);
    node *head2 = reverseList(l2);

    node *dummy = new node(-1);
    node *temp = dummy;

    int carry = 0;

    while(head1 || head2 || carry==1){
        int sum = 0;
        if(!head1){
            sum+=head1->data;
            head1=head1->next;
        }
        if(!head2){
            sum+=head2->data;
            head2=head2->next;
        }

        sum+=carry;
        carry = sum/10;
        temp->next = new node(sum%10);
        temp=temp->next;
    }

    node *ans = reverseList(dummy->next);
    return ans;
}

void print(node *head){
    if(!head)   return;

    node *temp = head;

    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}   

int main(){
    node *l1 = new node(3);
    l1->next = new node(4);
    l1->next->next = new node(2);

    node *l2 = new node(4);
    l2->next = new node(6);
    l2->next->next = new node(5);

    node *ans = addBothLists(l1,l2);

    print(ans);
    return 0;
}