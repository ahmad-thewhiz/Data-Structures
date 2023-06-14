//Merge Sort
//https://youtu.be/5Z9dn2WTg9o
//Time complexity - O(nlogn)

#include<stdio.h>

void merger(int arr[], int start, int mid, int end) {
    // Calculate the sizes of the two subarrays
    int n1 = mid - start + 1;
    int n2 = end - mid;

    // Create temporary arrays to store the subarrays
    int L[n1], R[n2];

    // Copy elements from the original array to the temporary left subarray (L)
    for (int i = 0; i < n1; i++)
        L[i] = arr[start + i];

    // Copy elements from the original array to the temporary right subarray (R)
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the two subarrays back into the original array in sorted order
    int i = 0; // Iterator for the left subarray (L)
    int j = 0; // Iterator for the right subarray (R)
    int k = start; // Iterator for the original array (arr)

    // Compare elements from the left and right subarrays and place them in the original array
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements from the left subarray (L) to the original array
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy any remaining elements from the right subarray (R) to the original array
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int start, int end) {
    if(start<end) { 
        int mid = start + (end-start)/2;

        merge_sort(arr, start, mid);
        merge_sort(arr, mid+1, end);

        merger(arr, start, mid, end);
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
    merge_sort(a, 0, no-1);
    printf("\nSorted array: ");
    display(a, no); // Display the sorted array
    return 0;
}