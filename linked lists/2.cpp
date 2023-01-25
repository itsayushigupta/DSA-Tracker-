#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int data)
    {
        this -> data = data;
        next = NULL;
    }
};

/*
node* takeInput()
{
    //using -1 as terminator
    int data;
    cin>>data;
    node* head = NULL;
    //null means LL is empty
    //head is a pointer var having address of 1st node
    while(data != -1)
    {
        node* newNode = new node(data);
        if(head == NULL)
            head = newNode;
        else
        {
            node* temp = head;
            while(temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
        cin>>data;
    }
    return head;
}
*/

node* takeInput()
{
    int data;
    cin>>data;

    node* head = NULL;
    node* tail= NULL;

    while(data != -1)
    {
        node* newNode = new node(data);
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
            //first node of LL
            //head and tail will be same
        }
        else
        {
            tail -> next = newNode;
            tail= tail -> next;
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


int main()
{
    node* head = takeInput();
    print(head);
}
