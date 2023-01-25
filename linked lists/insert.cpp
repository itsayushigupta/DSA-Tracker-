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

void print(node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout<< temp -> data <<" ";
        temp = temp  -> next;
    }
}

void insertNode(node* head, int i, int data)
{
    node* newNode = new node(data);
    int count = 0;
    node* temp = head;
    while(temp != NULL && count < i-1)
    {
        temp = temp -> next;
        count++;
    }
    node* a = temp -> next;
    temp -> next = newNode;
    newNode -> next = a;
}

int main()
{
    node* head = takeInput();
    print(head);
    int i, data;
    cin>>i>>data;
    insertNode(head, i, data);
    print(head);
}













