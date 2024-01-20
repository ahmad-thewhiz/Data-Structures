// One Odd Occuring
/*
 * I/P: arr[] = {4,3,4,4,4,5,5}
 * O/P: 3
 * I/P: arr[] = {8,7,7,8,8}
 * O/P: 8
 */

 import java.util.*;

 public class Main {
     /*
     Properties of XOR Operators
      * x ^ 0 = x
      * x ^ x = 0
      * x ^ x...^x (odd) = x
      * x ^ x...^x (even) = 0
      */
 
     /*
     arr[] = {4,4,7,4,8,7,7,7,8}
     (4^4^4)^(7^7^7^7)^(8^8)
     = 4 ^ 0 ^ 0
     = 4
     */ 
     public static int findOdd(int arr[], int n) {
         int res = arr[0];
         for(int i=1;i<n;i++)
             res = res^arr[i];
         return res;
     }
     public static void main(String args[]) {
         Scanner in=new Scanner(System.in);
         int num = in.nextInt();
         int arr[] = new int[num];
         for(int i=0;i<num;i++)
             arr[i] = in.nextInt();
         System.out.println("Number with odd occurences: " + findOdd(arr, num));
     }
 }