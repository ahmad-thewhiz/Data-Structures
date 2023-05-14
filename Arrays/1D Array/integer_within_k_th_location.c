#include<stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int i,j;
    int a[n];
    for(i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    int k,dist;
    scanf("%d",&k);
    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) {
            if(a[i]==a[j]) {
                dist=j-i;
            }
         
        }
    }
    if(dist==k) 
    printf("Yes");
    else
    printf("No");
    return 0;
}
