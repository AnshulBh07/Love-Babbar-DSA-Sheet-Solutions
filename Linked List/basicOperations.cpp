#include<iostream>
using namespace std;

//make linked list data structure 
class node{
    public:
    int data;
    node *next;

    node(){
        next = NULL;
    }
};

//class containing basic operation functions
class linkedList{
    public:
    node *head;
    linkedList(){
        head = NULL;
    }

    void create();
    void insert_beg();
    void insert_end();
    void insert_pos();
    void delete_beg();
    void delete_end();
    void delete_pos();
    void display();
};

void linkedList :: create(){
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

void linkedList :: insert_beg(){
    node *newnode = new node();

    if(newnode==NULL){
        cout<<"not enough memory!\n";
    }

    cout<<"\nEnter data : ";
    cin>>newnode->data;
    newnode->next=NULL;

    if(head==NULL){
        head = newnode;
    }

    newnode->next=head;
    head=newnode;
} 

void linkedList :: insert_end(){
    node *newnode = new node();
    if(newnode==NULL){
        cout<<"not enough space!\n";
    }

    cout<<"\nEnter data : ";
    cin>>newnode->data;
    newnode->next=NULL;
    if(head==NULL){
        newnode=head;
    }

    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}

void linkedList :: insert_pos(){
    node *newnode = new node();
    if(newnode==NULL){
        cout<<"not enough space!\n";
    }

    cout<<"\nEnter data : ";
    cin>>newnode->data;
    int pos;
    cout<<"Enter position : ";
    cin>>pos;

    node *temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

void linkedList :: delete_beg(){
    node *temp=head;
    if(head==NULL){
        cout<<"nothing to delete!";
    }
    if(head->next==NULL)
    free(head);

    head=head->next;
    temp->next=NULL;
    free(temp);
}

void linkedList :: delete_end(){
    node *temp=head;
    if(head==NULL){
        cout<<"nothing to delete!";
    }
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    temp->next=NULL;
}

void linkedList :: delete_pos(){
    if(head==NULL){
        cout<<"nothing to delete!";
    }
    int pos;
    cout<<"Enter position : ";
    cin>>pos;

    node *temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    temp->next=temp->next->next;
    temp->next->next=NULL;
}

void linkedList :: display(){
    node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    linkedList l;
    l.create();
    l.display();
    l.insert_beg();
    l.display();
    l.insert_end();
    l.display();
    l.insert_pos();
    l.display();
    l.delete_beg();
    l.display();
    l.delete_end();
    l.display();
    l.delete_pos();
    l.display();
    return 0;
}