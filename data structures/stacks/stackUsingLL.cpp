#include<iostream>
using namespace std;

template <typename T>
class node
{
public:
    T data;
    node<T> *next;

    node(T data)
    {
        this -> data = data;
        next = NULL;
    }
};

template <typename T>
class Stack
{
    node<T> *head;
    int Size; //no of elements in the stack

public:

    Stack()
    {
        head=NULL;
        Size=0;
    }

    int getSize()
    {
        return Size;
    }

    bool isEmpty()
    {
        return Size==0;
    }

    void push(T element)
    {
        node<T> *newNode=new node<T>(element);
        newNode->next=head;
        head=newNode;
        Size++;
    }

    T pop()
    {
        if(isEmpty()) return 0;
        T ans=head->data;  //storing the data in ans
        node<T> *temp=head;   //creating a temporary pointer to store address of the head
        head=head->next;  //moving the head
        delete temp;   //delete the temporary pointer
        Size--;
        return ans;
    }

    T top()
    {
        if(isEmpty()) return 0;
        else return head->data;
    }

};

int main() {
        Stack<int> s;
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50);

        cout<<s.top()<<endl;

        cout<<s.pop()<<endl;
        cout<<s.pop()<<endl;
        cout<<s.pop()<<endl;

        cout<<s.getSize()<<endl;

        cout<<s.isEmpty()<<endl;

    }


