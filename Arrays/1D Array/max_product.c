// Time-Complexity - O(n^3)

#include<stdio.h>

typedef struct {
    int ele1, ele2, ele3, product;
} OutputVal;

OutputVal maxProduct(int arr[], int n, OutputVal values) {
    int i, j, k, pro = 0, max = 0;
    for(i = 0; i < n - 2; i++) {
        for(j = i + 1; j < n - 1; j++) {
            for(k = j + 1; k < n; k++) {
                pro = arr[i] * arr[j] * arr[k];
                if(pro > max) {
                    max = pro;
                    values.product = max;
                    values.ele1 = arr[i];
                    values.ele2 = arr[j];
                    values.ele3 = arr[k];
                }
            }
        }
    }
    return values;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++) 
        scanf("%d", &a[i]);
    
    OutputVal values = {0, 0, 0, 0};
    values = maxProduct(a, n, values);

    printf("Triplet: (%d, %d, %d)\n", values.ele1, values.ele2, values.ele3);
    printf("Product: %d\n", values.product);
    
    return 0;
}
