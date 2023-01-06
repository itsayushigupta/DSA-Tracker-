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

void print(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout<< temp -> data <<" ";
        temp = temp  -> next;
    }
}

void printReverse(node *head){
    //recursive
	if(head == NULL) return;
	printReverse(head -> next);
	cout<<head -> data<<" ";
}

node *reverseLinkedList(node *head) {
    //iterative
      if (head == NULL || head->next == NULL) return head;
      node *current = head;
      node *prev = NULL;
      node *n;
      while (current != NULL){
        n = current->next;
        current->next = prev;
        prev = current;
        current = n;
      }
      return prev;
}

int main() {
    node* head = takeInput();
    cout<<endl<<"printing the LL: ";
    print(head);
    cout<<endl<<"reversing the LL(recursive)"<<endl;
    printReverse(head);
    cout<<endl<<"iterative"<<endl;
    node *rev=reverseLinkedList(head);
    print(rev);

}
