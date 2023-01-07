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

node* reverseKGroup(node* head, int k) {
        if(head==NULL) return NULL;
        if(k==0) return head;
        // to reverse first k nodes
        node* current=head;
        node* previous=NULL;
        node* next;
        int count=0;
        while(current!=NULL || count<k) {
            next=current->next;
            current->next=previous;
            previous=current;
            current=next;
            count++;
        }
        int len=0;
        node* temp=next;
        while(temp!= NULL) {
            len++;
            temp=temp->next;
        }

       if(next != NULL && len >= k) {
           head->next = reverseKGroup(next,k);
        }
       else
       head->next = next;
       return previous;
}

int main()
{
    node* head = takeInput();
    cout<<endl<<"printing the LL: ";
    print(head);
    int k;
    cout<<endl<<"enter k: ";
    cin>>k;
    cout<<endl<<"reversed in k groups LL: "<<endl;
    node* revK=reverseKGroup(head,k);
    print(revK);

}


