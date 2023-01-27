#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;

    //constructor
    node(int data)
    {
        this -> data = data;
        next = NULL;
    }
};

node* takeInput()
{
    int data;
    cin>>data;
    node* head = NULL;
    node* tail = NULL;

    while(data != -1)
    {
        node* n = new node(data);

        if(head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail -> next = n;   // linking the address
            tail = n;   // updating the tail
        }
        cin>>data;
    }
    return head;
}

void print(node* &head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout<< temp -> data <<" ";
        temp = temp  -> next;
    }
}

void InsertAtHead(node* &head, int d)
{
    //new node
    node* temp = new node(d);
    temp -> next = head;
    head = temp;
}

void InsertAtTail(node* &tail, int d)
{
    //new node
    node* temp = new node(d);
    tail -> next = temp;
    tail = temp;
}

int main()
{
    node* head = takeInput();
    cout<<endl<<"printing the LL: ";
    print(head);
    int d;
    cout<<endl<<"enter element to be inserted at head= ";
    cin>>d;
    InsertAtHead(head,d);
    print(head);

    node* tail;
    int d1;
    cout<<endl<<"enter element to be inserted at tail= ";
    cin>>d1;
    InsertAtTail(tail,d1);
    print(head);
}
