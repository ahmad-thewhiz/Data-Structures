#include<stdio.h>


int binarysearch(int arr[], int size, int ele) {
    int low=0,high=size-1;
    while(low<=high) {
        int mid = (low+high)/2;
        
        if(arr[mid]==ele)
            return mid;
        if(arr[mid]<ele)
            low=mid+1;
        else
            high = mid-1;
    }
    return -1;
}

int main() {
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) 
        scanf("%d",&a[i]);
    int no;
    scanf("%d",&no);
    
    int result = binarysearch(a,n,no);
    if(result==-1)  
        printf("Element %d is not present in array\n",no);
    else
        printf("Element %d is present at index %d\n",no,result);
        
    return 0;
}
