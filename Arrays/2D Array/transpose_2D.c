#include<stdio.h>
int main() {
    int m,n;
    scanf("%d %d",&m,&n);
    int a[10][10];
    int b[10][10];
    int i,j;
    for(i=0;i<m;i++) {
        for(j=0;j<n;j++) {
            scanf("%d",&a[i][j]);
            b[j][i]=a[i][j];
        }
    }
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            b[j][i]=a[i][j];
            }
    }
    printf("Transpose of the matrix:\n");
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
    return(0);
}