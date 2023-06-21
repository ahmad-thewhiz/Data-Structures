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

void delete_from_heap(int arr[], int n) {
    int x,i,j,temp;

    int val=arr[1];
    x=arr[n]; //last element in x
    arr[1]=arr[n];
    arr[n] = val; //last element copied to first place because in heap we cannot delete any other element
    i=1; //pointing to first element
    j=i*2; //pointing to the child node of i

    while(j<=n-1) {
        if(j<n-1 && arr[j+1]>arr[j]) //first check if right child is greater than left child
            j=j+1; //j now pointing to right child
        
        if(arr[i]<arr[j]) { //check is parent node is less than its child node
            temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i=j; //i should point to its child which is greater than it
            j=j*2; //j should point on its child now
        }      
        else 
            break;
    }
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

    for(int i=n;i>1;i--)
        delete_from_heap(a,i);

    printf("\n");    

    //Display
    for(int i=1;i<=n;i++)
        printf("%d ", a[i]);

    return 0;
}