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

void deleteNode(node* head, int pos){
    if(pos==1){
        // deleting first node
        node* temp = head;
        head = head -> next;
        // deallocating the first node; before deleting, point them to null so that they don't point to an address
        temp -> next = NULL;
        delete temp;
    }
    else{
        // deleting any middle node or last node
        node* current = head;
        node* previous = NULL;
        int count = 1;
        while(count < pos){
            // prev and curr ko aage aage shift karvana hoga
            previous = current;
            current = current -> next;
            count++;
        }
        previous -> next = current -> next;
        current -> next = NULL;
        delete current;
    }
}

int main(){
    node* head = takeInput();
    print(head);
    int pos;
    cout<<endl<<"enter node you want to delete: ";
    cin>>pos;
    deleteNode(head, pos);
    cout<<endl<<"printing LL after deletion: "<<endl;
    print(head);
}
