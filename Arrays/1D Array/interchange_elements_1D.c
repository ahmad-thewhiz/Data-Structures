#include<stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int i,ilar,isml,temp;
    int a[n];
    
    for(i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    int sml=a[1];
    int lar=a[1];
    for(i=0;i<n;i++) {
        if(a[i]<sml) {
            isml=i;
            sml=a[i];
        }
        if(a[i]>lar) {
            ilar=i;
            lar=a[i];
        }
    }
        temp=a[ilar];
        a[ilar]=a[isml];
        a[isml]=temp;
        
        printf("The Array after interchanging the largest and smallest element :\n");
        for(i=0;i<n;i++){
            printf("%d\t",a[i]);
        }
        return(0);
    }


