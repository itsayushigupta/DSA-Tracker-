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

// FOR PALINDROME, FIRST REVERSE THE LL AND THEN COMPARE THE BOTH HALVES

node *midpoint(node *head)
{
    if(head==NULL) return head;
    node *slow=head->next;
    node *fast=head->next->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

node *reverseLinkedList(node *head) {
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

bool isPalindrome(node *head){
    // edge case
    if(head==NULL || head->next==NULL) return true;
    // to find the middle point
    node *mid=midpoint(head);
    // reverse ll after mid point
    node *temp=mid->next;
    mid->next=reverseLinkedList(temp);

    //comparing both nodes
    node *head1=head;
    node *head2=mid->next;
    while(head2!=NULL) {
        if(head1->data != head2->data) return false;
        head1=head1->next;
        head2=head2->next;
    }
    return true;
}

int main()
{
    node* head = takeInput();
    cout<<endl<<"printing the LL: ";
    print(head);
    cout<<endl<<"palindrome or not: "<<isPalindrome(head);
}
