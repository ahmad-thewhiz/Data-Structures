//Insertion Sort
//Time complesity - O(n^2)

#include<stdio.h>

void insertion_sort(int arr[], int n) {
    int i, j, temp;

    // Iterate through the array starting from the second element
    for (i = 1; i < n; i++) {
        temp = arr[i];  // Store the current element to be inserted

        // Compare the current element with the sorted part of the array on its left
        // Shift elements to the right until the correct position is found
        for (j = i - 1; j >= 0 && arr[j] > temp; j--) {
            arr[j + 1] = arr[j];  // Shift the element to the right
        }
        arr[j + 1] = temp;  // Insert the current element at the correct position
    }
}

void display(int arr[], int no) {
    for(int i=0;i<no;i++)
        printf("%d ",arr[i]);
}

int main() {
    int no;
    printf("Enter size of the array: ");
    scanf("%d",&no);
    int a[no];
    printf("\nEnter elements: ");
    for(int i=0;i<no;i++)
        scanf("%d",&a[i]);
    insertion_sort(a,no);
    printf("\nSorted Array: ");
    display(a, no);
    return 0;
}
