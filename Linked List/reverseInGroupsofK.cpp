#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;

    node() 
    {
        this->next = NULL;
    }
};

class LinkedList
{
    public : 
    node *head;

    LinkedList()
    {
        head = NULL;
    }

    void create(){
    int n,d;
    cout<<"Enter the size of initial list : ";
    cin>>n;
    head = new node();

    if(head==NULL){
        cout<<"Memory out of Space!\n";
    }
    cout<<"Enter data for head node : ";
    cin>>head->data;
    head->next=NULL;
    node *temp = head;

    for(int i=1;i<n;i++){
        node *newnode = new node();
        cout<<"Enter data for node "<<i+1<<" : ";
        cin>>newnode->data;
        newnode->next=NULL;
        temp->next=newnode;
        temp=temp->next;
    }
    }

    void reverseGrouped(node *head,int k){
        node *curr=head;
        node *after=nullptr, *prev=nullptr;
        int i = k;
        while(curr!=NULL && i!=0){
            after=curr->next;
            curr->next = prev;
            prev=curr;
            curr=after;
            i--;
        }
        if(curr!=nullptr){
            reverseGrouped(after,k);
        }
        head=prev;
    }

    void display(){
    node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
    }
};

int main()
{
    LinkedList l;
    l.create();
    l.display();
    return 0;
}