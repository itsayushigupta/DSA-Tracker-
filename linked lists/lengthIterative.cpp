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

int length(node* head)
{
    int len=0;  // initializing the length of LL as zero
    node* temp = head;
    while(temp != NULL)
    {
        temp = temp -> next;
        len++;
    }
    return len;
}

int main()
{
    node* head = takeInput();
    cout<<endl<<"printing the LL: ";
    print(head);
    cout<<endl<<"length of the LL is: "<<length(head);
}
