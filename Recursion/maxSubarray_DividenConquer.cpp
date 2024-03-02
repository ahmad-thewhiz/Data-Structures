#include<bits/stdc++.h>
using namespace std;

int max(int a, int b) {
    return (a>b)?a:b;
}

int max(int a, int b, int  c) {
    return max(max(a,b),c);
}

int maxSumCrossing(int arr[], int l, int mid, int h) {
    int rsum=INT_MIN, lsum=INT_MIN, sum=0;
    for(int i=mid; i>=l; i--) {
        sum += arr[i];
        if(lsum<sum)
            lsum=sum;
    }
    sum = 0;
    for(int i=mid; i<=h; i++) {
        sum += arr[i];
        if(rsum<sum)
            rsum=sum;
    }
    return max(lsum, rsum, lsum+rsum-arr[mid]);
}


int maxSumArray(int arr[], int l, int h) {
    if(l>h)
        return INT_MIN;
    if(l==h)
        return arr[l];
    int mid = (l+h)/2;
    return max(maxSumArray(arr, l, mid-1), maxSumArray(arr, mid+1, h), maxSumCrossing(arr, l, mid, h));
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) 
        cin>>arr[i];
    int max = maxSumArray(arr, 0, n-1);
    cout<<endl<<"Max Sum: "<<max;
    return 0;
}
