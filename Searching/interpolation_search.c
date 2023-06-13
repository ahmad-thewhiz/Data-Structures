#include<stdio.h>

// Function to perform interpolation search on a sorted array
int interpolation_search(int arr[], int start, int end, int no) {
    int pos;
    
    // Check if the search is within the range of the array and the target element is within the range of values
    if (start <= end && no > arr[start] && no < arr[end]) {
        
        // Calculate the estimated position using interpolation formula
        pos = start + (((double)(end - start) / (arr[end] - arr[start])) * (no - arr[start]));
        
        // If the element at the estimated position matches the target element, return the position
        if (arr[pos] == no)
            return pos;
        
        // If the element at the estimated position is smaller than the target element,
        // recursively search in the right subarray
        else if (arr[pos] < no)
            interpolation_search(arr, pos + 1, end, no);
        
        // If the element at the estimated position is greater than the target element,
        // recursively search in the left subarray
        else
            interpolation_search(arr, start, pos - 1, no);
    }
    
    // If the target element is not found, return -1
    return -1;
}

int main() {
    int no;
    printf("Enter the size of the array: ");
    scanf("%d", &no);
    int a[no];
    
    printf("\nEnter the sorted array:\n");
    for (int i = 0; i < no; i++) {
        scanf("%d", &a[i]);
    }
    
    int ele;
    printf("\nEnter the element to be searched: ");
    scanf("%d", &ele);
    
    // Perform interpolation search on the array
    int index = interpolation_search(a, 0, no - 1, ele);
    
    // Display the result based on the search result
    if (index != -1)
        printf("\nElement found at index %d", index);
    else
        printf("\nElement not found");
    
    return 0;
}
