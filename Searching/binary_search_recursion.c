#include<stdio.h>

int binary_search_recursion(int arr[], int low, int high, int no) {
    if(low>high) 
        return -1;
    int mid=(low+high)/2;
    if(no==arr[mid])
        return mid;
    else if(no<arr[mid])
        return binary_search_recursion(arr,low,mid-1,no);
    else
        return binary_search_recursion(arr,mid+1,high,no);
}

int main() {
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int no;
    scanf("%d",&no);
    int result = binary_search_recursion(a,0,n-1,no);
    if(result!=-1)
        printf("Element %d is present at index %d",no,result);
    else
        printf("Element %d is not present in array",no);
    return 0;
}
