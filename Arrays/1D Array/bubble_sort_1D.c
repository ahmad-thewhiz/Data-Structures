#include<stdio.h>
int main() {
    
    int n;
    scanf("%d",&n);
    
    int a[n];
    int i,j,temp;
    
    for(i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    
    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) {
            temp=0;
            if(a[i]>a[j]) {
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
    }
    for(i=0;i<n;i++) {
        printf("%d\t",a[i]);
    }
    return(0);
}
