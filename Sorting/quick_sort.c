//Quick Sort
//Time complexity - 
//Average - O(n*logn)
//Worst - O(n^2)
//https://youtu.be/WprjBK0p6rw

#include<stdio.h>

// Function to swap two elements in an array
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to partition the array based on a pivot element
int partition(int arr[], int start, int end) {
    int pivot = arr[end]; // Choosing the pivot as the last element of the array
    int i = start - 1; // Index of the smaller element
    
    // Iterate from 'start' to 'end-1'
    for (int j = start; j < end; j++) {
        if (arr[j] < pivot) { // If current element is smaller than the pivot
            i++;
            swap(arr, i, j); // Swap the elements to move smaller elements to the left of the pivot
        }
    }
    
    swap(arr, i + 1, end); // Swap the pivot element to its correct position
    return (i + 1); // Return the index of the pivot element
}

// Function to perform Quick Sort recursively
void quick_sort(int arr[], int start, int end) {
    if (start < end) { // If there is more than one element in the array
        int part_i = partition(arr, start, end); // Partition the array and get the pivot index
        quick_sort(arr, start, part_i - 1); // Recursively sort the elements before the pivot
        quick_sort(arr, part_i + 1, end); // Recursively sort the elements after the pivot
    }
}

// Function to display the elements of the array
void display(int arr[], int no) {
    for (int i = 0; i < no; i++)
        printf("%d ", arr[i]);
}

// Main function
int main() {
    int no;
    printf("Enter the size of the array: ");
    scanf("%d", &no);
    int a[no];
    printf("\nEnter elements: ");
    for (int i = 0; i < no; i++)
        scanf("%d", &a[i]);
    quick_sort(a, 0, no - 1); // Sort the array using Quick Sort
    printf("\nSorted array: ");
    display(a, no); // Display the sorted array
    return 0;
}
