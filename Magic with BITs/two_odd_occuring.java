// Two Odd Occuring
/*
I/P: arr[] = {3,4,3,4,5,4,4,6,7,7}
O/P: 5, 6
I/P: arr[] = {1,3,2,3,3,1}
O/P: 2, 3
*/

 import java.util.*;

 public class Main {

    public static void oddAppearing(int arr[], int n) {
        int x=arr[0];
        for(int i=1;i<n;i++)
            x = x^arr[i];
        int k = (x&(~(x-1)));
        int res1=0, res2=0;
        for(int i=0;i<n;i++) {
            if((arr[i]&k)!=0)
                res1=res1^arr[i];
            else
                res2=res2^arr[i];
        }
        System.out.println(res1+" and "+res2);
    }
    public static void main(String args[]) {
         Scanner in=new Scanner(System.in);
         Scanner in=new Scanner(System.in);
         int num = in.nextInt();
         int arr[] = new int[num];
         for(int i=0;i<num;i++)
             arr[i] = in.nextInt();
        oddAppearing(arr, num);
    }
 }