#include <iostream>
#include<unordered_set>
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

node *removeDuplicate1(node *head){
    if(!head) return head;

    unordered_set<int> s;
    node *temp1 = head,*temp2=head->next;

    while(temp2){
        s.insert(temp1->data);

        if(s.find(temp2->data)!=s.end()){   //temp1=temp2
            node *del = temp2;
            temp2=temp2->next;
            temp1->next = temp2;
            delete del;
        }
        else{
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    return head;
}

int main()
{
    node *head = newNode(2);
    head->next = newNode(2);
    head->next->next = newNode(2);
    head->next->next->next = newNode(2);
    head->next->next->next->next = newNode(2);

    node *ans = removeDuplicate1(head);
    display(ans);
    return 0;
}

