#include<bits/stdc++.h>
using namespace std;

void print(int i, vector<int>& ds, int sum, int k, int a[], int n) {
    //base case
    if(i==n) {
        if(sum==k) {
          for(auto it: ds) cout<<it<<" ";
          cout<<endl;
        }
        return;
    }

    // take or pick the particular index into the subsequence
    ds.push_back(a[i]);
    sum=sum+a[i];
    print(i+1, ds, sum, k, a, n);
    sum=sum-a[i];
    ds.pop_back();

    //not pick, this element is not added into the subsequence
    print(i+1, ds, sum, k, a, n);
}

int main() {
    int a[]={1, 2, 1};
    int n=3;
    int k=2;
    vector<int> ds;
    print(0, ds, 0, k, a, n);
    return 0;
}
