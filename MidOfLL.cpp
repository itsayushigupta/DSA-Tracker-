#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
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

node *midpoint(node *head)
{
    if(head==NULL) return head;
    node *slow=head;
    node *fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

int main()
{
    node* head = takeInput();
    cout<<endl<<"printing the LL: ";
    print(head);
    int d;
    cout<<endl<<"middle of ll";
    midpoint(head);
    print(head);


}
