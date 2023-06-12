#include<stdio.h>

int linear_search_recursion(int arr[], int size, int ele) {
    if(size<0)
        return -1;
    if(arr[size]==ele)
        return size;
    return linear_search_recursion(arr,size-1,ele);
}

int main() {
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int no;
    scanf("%d",&no);
    int result = linear_search_recursion(a,n,no);
    if(result!=-1)
        printf("Element %d is present at index %d",no,result);
    else
        printf("Element %d is not present",no);
    return 0;
}
