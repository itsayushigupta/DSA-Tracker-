#include<iostream>
using namespace std;
#include <climits>

template <typename T>

class StackUsingArray {
    T *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray()
    {
        data=new T[4];
        nextIndex=0;
        capacity=4;
    }

    //return the size of the stack
    int Size()
    {
        return nextIndex;
    }

    //check if stack is filled or empty
    bool isEmpty()
    {
        if(nextIndex==0) return true;
        else return false;
    }

    //insert element
    void push(T element)
    {
        if(nextIndex==capacity)
        {
            //a new array of double the size is created
            T *newData = new T[2*capacity];
            //copying the old array elements into new array
            for(int i=0; i<capacity; i++)
            {
                newData[i]=data[i];
            }

            //increasing the capacity and deallocating the old array now
            capacity = 2*capacity;
            delete [] data;
            data = newData;
        }
        data[nextIndex] = element;
		nextIndex++;
    }

    // delete element
	T pop() {
		if(isEmpty()) {
			cout << "Stack is empty " << endl;
			return 0;
		}
		nextIndex--;
		return data[nextIndex];
	}

     T top() {
		if(isEmpty()) {
			cout << "Stack is empty " << endl;
			return 0;
		}
		return data[nextIndex - 1];
	}
};

 int main() {
        StackUsingArray<int> s;
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50);

        cout<<s.top()<<endl;

        cout<<s.pop()<<endl;
        cout<<s.pop()<<endl;
        cout<<s.pop()<<endl;

        cout<<s.Size()<<endl;

        cout<<s.isEmpty()<<endl;

    }
