#include<stdio.h>

// Function to display the elements of the array
void display(int arr[], int no) {
    for (int i = 0; i < no; i++)
        printf("%d ", arr[i]);
}

int main() {
    int no;
    printf("Enter the size of Array: ");
    scanf("%d",&no);
    int a[no];
    printf("\nEnter elements: ");
    for (int i = 0; i < no; i++)
        scanf("%d", &a[i]);
    printf("\nEnter location of the element to be deleted: ");
    int loc;
    scanf("%d",&loc);
    for(int i=loc-1;i<no-1;i++)
        a[i]=a[i+1];
    printf("\nUpdated array: ");
    display(a, no-1);
    return 0;
}