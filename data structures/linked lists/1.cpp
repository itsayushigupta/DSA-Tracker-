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

void print(node* head)
{
    // so that we don't lose the head node address so we create a temporary pointer
    node* temp = head;
    // with the help of head, we can traverse through the whole LL
    while(temp != NULL)
    {
        cout<< temp -> data <<" ";
        temp = temp  -> next;
    }
}

int main()
{
    /*
    // STATICALLY
    // first node---> head , last node---> tail
    node n1(1);
    // to store node n1 address
    node* head = &n1;

    node n2(2);

    // now we have to connect the two nodes
    // for this, we have to store node n2 address in the (next) of node n1
    n1.next = &n2;

    cout<<n1.data<<" "<<n2.data<<endl;

    // printing nodes with the help of HEAD only
    cout<<head->data<<endl;

    // DYNAMICALLY
    node* n3 = new node(10);
    node* head = n3;
    node* n4 = new node(20);
    n3 -> next = n4;
    */

    node n1(1);
    node* head = &n1;
    node n2(2);
    node n3(3);
    node n4(4);
    node n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    // printing the linked list
    // just need to pass the head of the LL, no need to pass the length of the LL
    print(head);







}
