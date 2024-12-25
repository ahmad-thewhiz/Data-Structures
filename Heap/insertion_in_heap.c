#include<stdio.h>

void insert_in_heap(int arr[], int n) {
    int temp, i=n;
    temp = arr[i];

    //runs until the child node is greater than its parent node
    while(i>1 && temp>arr[i/2]) {
        arr[i]=arr[i/2];
        i=i/2;
    }

    arr[i]=temp;
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);

    //We have to take first element as 0 because we have to perform insert operation starting from index to n
    int a[n+1];
    a[0]=0;

    //Taking values from the user
    for(int i=1;i<=n;i++) 
        scanf("%d",&a[i]);

    //Calling the function to perform insertion in heap
    for(int i=2;i<=n;i++)
        insert_in_heap(a,i);

    //Display
    for(int i=1;i<=n;i++)
        printf("%d ", a[i]);

    return 0;
}


// Time Complexity:
// O(log n)
