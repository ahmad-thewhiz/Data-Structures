#include<stdio.h>
int rev=0;
int reverse(int num) {
    int dig=0;
    
    if(num) {
        dig=num%10;
        rev=rev*10+dig;
        reverse(num/10);
    }
    else
    return rev;
    return rev;
}

int main() {
    int num;
    scanf("%d",&num);
    printf("%d",reverse(num));
}