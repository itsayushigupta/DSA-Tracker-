#include<bits/stdc++.h>
using namespace std;

void print(int i, vector<int>& ds, int a[], int n) {
    //base case
    if(i==n) {
        for(auto it: ds) {
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }

    // take or pick the particular index into the subsequence
    ds.push_back(a[i]);
    print(i+1, ds, a, n);
    ds.pop_back();

    //not pick, this element is not added into the subsequence
    print(i+1, ds, a, n);
}

int main() {
    int a[]={3, 1, 2};
    int n=3;
    vector<int> ds;
    print(0, ds, a, n);
    return 0;
}
