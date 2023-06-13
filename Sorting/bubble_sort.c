//Bubble Sort
//Time Complexity - O(n^2)

#include<stdio.h>

void bubble_sort(int arr[], int no) {
    int i, j, temp;

    // Iterate through the array
    // Each iteration places the largest element at the end of the unsorted part
    for (i = 0; i < no; i++) {
        
        // Compare adjacent elements and swap if necessary
        // The largest element "bubbles" to the end of the unsorted part in each iteration
        for (j = 0; j < no - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void display(int arr[], int no) {
    for(int i=0;i<no;i++)
        printf("%d ",arr[i]);
}

int main() {
    int no;
    printf("Enter the size of array: ");
    scanf("%d",&no);
    int a[no];
    printf("\nEnter elemetns: ");
    for(int i=0;i<no;i++)
        scanf("%d",&a[i]);
    bubble_sort(a,no);
    printf("\nSorted array: ");
    display(a,no);
    return 0;
}
