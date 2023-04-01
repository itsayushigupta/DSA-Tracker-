#include<bits/stdc++.h>
using namespace std;

int print(int i, int sum, int k, int a[], int n) {
    //base case
    if(i==n) {
        if(sum==k)
        //condition satisfied
        return 1;
        //condition not satisfied
        else return 0;
    }

    // take or pick the particular index into the subsequence
    sum=sum+a[i];
    int l=print(i+1, sum, k, a, n);
    sum=sum-a[i];

    //not pick, this element is not added into the subsequence
    int r=print(i+1, sum, k, a, n);

    return l+r;
}

int main() {
    int a[]={1, 2, 1};
    int n=3;
    int k=2;
    cout<<print(0, 0, k, a, n);
    return 0;
}
