// Bit-Handling -- Power of Two

import java.util.*;

public class Main {

    // Naive Solution O(n) 
    public static boolean isPow2(int n) {
        if(n==0)
            return false;
        while(n!=1) {
            if(n%2!=0)
                return false;
            n/=2;
        }
        return true;
    }

    //Efficient Solution O(1)-- Brian Kernighan Algorithm
    /*
    1: 00...001
    2: 00...010
    4: 00...100
    */

    public static boolean isPower2(int n) {
        if(n==0)
            return false;
        return ((n&(n-1))==0); //when value is 0 then num is power of 2
    }
    public static void main(String args[]) {
        Scanner in=new Scanner(System.in);
        int num = in.nextInt();
        boolean flag = isPower2(num);
        if(flag)
            System.out.println("Yes");
        else
            System.out.println("No");
    }
}
