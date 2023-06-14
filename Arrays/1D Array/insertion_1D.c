#include<stdio.h>

// Function to display the elements of the array
void display(int arr[], int no) {
    for (int i = 0; i < no; i++)
        printf("%d ", arr[i]);
}

int main() {
    int a[1000]={0};
    int no;
    printf("Enter the size of Array: ");
    scanf("%d",&no);
    printf("\nEnter elements: ");
    for (int i = 0; i < no; i++)
        scanf("%d", &a[i]);
    printf("\nEnter location and the elements: ");
    int loc, ele;
    scanf("%d %d",&loc, &ele);
    for (int i = no; i >= loc; i--) {
        a[i] = a[i - 1];
    }
    a[loc-1]=ele;
    printf("\nUpdated array: ");
    display(a, no+1);
    return 0;
}
