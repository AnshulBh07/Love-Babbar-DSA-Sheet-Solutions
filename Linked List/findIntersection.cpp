#include <iostream>
#include<set>
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

node *findIntersection(node *head1,node *head2){
    set<int> helper;
    node *temp1=head1,*temp2=head2;
    while(temp1!=NULL){
        helper.insert(temp1->data);
    }
    while(temp2!=NULL){
        helper.insert(temp2->data);
    }
    node *head3;
}

int main()
{
    node *head1 = newNode(50);
    head1->next = newNode(10);
    head1->next->next = newNode(15);
    head1->next->next->next = newNode(20);
    head1->next->next->next->next = newNode(35);

    node *head2 = newNode(1);
    head2->next = newNode(10);
    head2->next->next = newNode(15);
    head2->next->next->next = newNode(32);

    node *ans = findIntersection(head1,head2);
    display(ans);
    return 0;
}

