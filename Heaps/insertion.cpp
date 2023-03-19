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
};

int main() {
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    return 0;
}

/* TC- value is inserted in the array and then
   compared with the parent node's value
   TC-O(log N)
