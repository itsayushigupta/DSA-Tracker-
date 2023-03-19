#include<iostream>
using namespace std;

class heap {
public:
    int arr[100];
    int total=0;

    heap() {
        arr[0]=-1;
        total=0;
    }

    void insert(int val) {
        //increase total
        total=total+1;
        //where we have to insert the value
        int index=total;
        arr[index]=val;

        while(index>1) {
            int parent=index/2;

            if(arr[parent]<arr[index]) {
                swap(arr[parent], arr[index]);
                //update parent
                index=parent;
            }
            else {
                return;
            }
        }
    }

    void print() {
        for(int i=1; i<=total; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    //deletion form heap
    void del() {
        if(total==0) {
            cout<<"nothing to delete"<<endl;
            return;
        }

        //1. put last element into first index
        arr[1]=arr[total];
        //2. remove last element
        total--;

        //3. take root node to its correct position
        int i=1;
        while(i<total) {
            int leftIndex=2*i;
            int rightIndex=2*i+1;

            if(leftIndex<total && arr[i]<arr[leftIndex]) {
                swap(arr[i], arr[leftIndex]);
                i=leftIndex;
            }

            else if(rightIndex<total && arr[i]<arr[rightIndex]) {
                swap(arr[i], arr[rightIndex]);
                i=rightIndex;
            }

            else {
                return;
            }

        }
    }
};

int main() {
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    cout<<endl;

    h.del();
    h.print();

    return 0;
}
