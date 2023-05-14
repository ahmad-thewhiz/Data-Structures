#include<stdio.h>

void l_search(int arr[], int n, int no) {
    int i;
    int pos,count=0;
    for(i=0;i<n;i++) {
        if(arr[i]==no) {
            count = 1;
            pos=i;
            break;
        }
    }
    if(count==1) {
        printf("%d is present at location %d.",no,(pos+1));
    }
    else {
        printf("%d is not present in array.",no);
    }
}

int main() {
    int n;
    scanf("%d",&n);
    int i,no;
    int arr[n];
    for(i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&no);
    l_search(arr,n,no);
}
