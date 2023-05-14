#include<stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int a[n];
    int i, count=0, no,pos;
    for(i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    scanf("%d",&no);
    for(i=0;i<n;i++) {
        if(a[i]==no)
         {
             count=1;
             pos=i;
             break;
         }
    }
    if(count==1) {
        printf("We found the Search Element %d at Position %d",no,i+1);
    }
    else {
        printf("Sorry!! We haven't found the the Search Element %d",no);
    }
}