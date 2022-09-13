#include <iostream>
#include<vector>
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

bool isPalindrome(node *head){
    vector<int> helper;
    if(head==NULL || head->next==NULL)
    return false;

    node*temp=head;
    while(temp!=NULL){
        helper.push_back(temp->data);
        temp=temp->next;
    }

    int i=0,j=helper.size()-1;
    while(i<j){
        if(helper[i]!=helper[j])
        return false;

        i++;
        j--;
    }
    return true;
}

int main()
{
    node *head = newNode(2);
    head->next = newNode(2);
    head->next->next = newNode(5);
    head->next->next->next = newNode(2);
    head->next->next->next->next = newNode(3);

    display(head);
    cout<<isPalindrome(head);
    return 0;
}