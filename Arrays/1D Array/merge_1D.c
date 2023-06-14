#include<stdio.h>

// Function to display the elements of the array
void display(int arr[], int no) {
    for (int i = 0; i < no; i++)
        printf("%d ", arr[i]);
}

int main() {
    int no1,no2;
    printf("Enter the size of Array 1: ");
    scanf("%d",&no1);
    int a[no1];
    printf("\nEnter elements: ");
    for (int i = 0; i < no1; i++)
        scanf("%d", &a[i]);
    printf("Enter the size of Array 2: ");
    scanf("%d",&no2);
    int b[no2];
    printf("\nEnter elements: ");
    for (int i = 0; i < no2; i++)
        scanf("%d", &b[i]);
    
    int c[no1+no2];
    for(int i=0;i<no1+no2;i++) {
        if(i<no1)
            c[i]=a[i];
        else
            c[i]=b[i-no1];
    }
    printf("\nUpdated array: ");
    display(c, no1+no2);
    return 0;
}