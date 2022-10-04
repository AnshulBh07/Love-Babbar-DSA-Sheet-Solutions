#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

node *insertAtEnd(node *head, int data)
{
    if (!head)
        return new node(data);

    node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }

    temp->next = new node(data);

    return head;
}

node *reverseList(node *head)
{
    if (!head)
        return head;

    node *curr = head, *prev = nullptr, *after = nullptr;
    while (curr)
    {
        after = curr->next;
        curr->next = prev;
        prev = curr;
        curr = after;
    }
    return prev;
}

node *addTwoNumbers(node *head1, node *head2)
{
    if (!head1)
        return head2;
    if (!head2)
        return head1;

    node *newhead1 = reverseList(head1);
    node *newhead2 = reverseList(head2);
    node *head3;

    node *temp1 = newhead1, *temp2 = newhead2;
    int carry = 0, x;
    while (temp1 || temp2)
    {
        x = temp1->data + temp2->data + carry;
        carry = x / 10;
        if (carry)
        {
            x = x % 10;
        }
        head3 = insertAtEnd(head3, x);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if (temp1)
    {
        while (temp1 && carry)
        {
            x = temp1->data;
            x += 1;
            carry = x / 10;
            if (carry)
            {
                x = x % 10;
            }
            head3 = insertAtEnd(head3, x);
            temp1 = temp1->next;
        }
        // in case of a carry existing even after the complete list has been traversed e.g. 999
        if (carry)
        {
            head3 = insertAtEnd(head3, carry);
        }
    }
    if(temp2){
        while (temp2 && carry)
        {
            x = temp2->data;
            x += 1;
            carry = x / 10;
            if (carry)
            {
                x = x % 10;
            }
            head3 = insertAtEnd(head3, x);
            temp2 = temp2->next;
        }
        // in case of a carry existing even after the complete list has been traversed e.g. 999
        if (carry)
        {
            head3 = insertAtEnd(head3, carry);
        }
    }
}

int main()
{
    node *head1 = new node(1);
    head1->next = new node(9);
    head1->next->next = new node(0);

    node *head2 = new node(2);
    head2->next = new node(5);
    return 0;
}