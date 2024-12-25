#include<stdio.h>

void insert_in_heap(int arr[], int n) {
    int temp, i = n;
    temp = arr[i];

    // Runs until the child node is greater than its parent node
    while (i > 1 && temp > arr[i / 2]) {
        arr[i] = arr[i / 2];
        i = i / 2;
    }

    arr[i] = temp;
}

int delete_from_heap(int arr[], int *n) {
    if (*n < 1) {
        printf("Heap is empty!\n");
        return -1;
    }

    int val = arr[1]; // Root value to be deleted
    int last = arr[*n]; // Last element in the heap
    arr[1] = last; // Replace root with the last element
    (*n)--; // Decrease heap size

    int i = 1, j = 2 * i; // Start heapify from root

    while (j <= *n) {
        // Check if right child exists and is greater than left child
        if (j + 1 <= *n && arr[j + 1] > arr[j]) 
            j = j + 1;

        // If parent is smaller than the larger child
        if (arr[i] < arr[j]) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i = j; // Move to the child node
            j = 2 * i;
        } else {
            break;
        }
    }

    return val;
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Initialize the array for heap, with size n+1
    int a[n + 1];
    a[0] = 0; // Dummy element

    printf("Enter the elements: ");
    // Taking values from the user
    for (int i = 1; i <= n; i++) 
        scanf("%d", &a[i]);

    // Calling the function to perform insertion in heap
    for (int i = 2; i <= n; i++)
        insert_in_heap(a, i);

    printf("Heap after insertion: ");
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n");

    // Deleting the root element from the heap
    int deleted_val = delete_from_heap(a, &n);
    if (deleted_val != -1) 
        printf("Deleted element from the heap: %d\n", deleted_val);

    printf("Heap after deletion: ");
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
