//Selection Sort 
//Time complexity - O(n^2)

#include <stdio.h>

void selection_sort(int arr[], int n) {
    int i, j, temp;

    // Iterate through the array from the first element to the second-to-last element
    for (i = 0; i < n - 1; i++) {

        // Find the minimum element in the unsorted part of the array
        // Starting from the next element after the current element (i+1)
        for (j = i + 1; j < n; j++) {

            // If a smaller element is found, swap it with the current element
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int no;
    printf("Enter the size of array: ");
    scanf("%d", &no);
    int a[no];
    printf("\nEnter Elements:\n");
    for (int i = 0; i < no; i++) {
        scanf("%d", &a[i]);
    }
    selection_sort(a, no);
    printf("\nSorted Array:\n");
    display(a, no);
    return 0;
}
