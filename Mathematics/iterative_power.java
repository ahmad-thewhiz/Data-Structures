import java.util.*;

class Main {

    static long iterative_power(int a, int x) {
        long res = 1;
        while(x>0) {
            if(x%2!=0) { // when bit is 1
                res = res * a;
            }
            a = a*a; //in every iteration the current number becomes its square or the power of the number increases by 2
            x = x/2; //everytime power is divided by 2
            // x = x>>1; it means x is divided by 2^(1)
        }
        return res;
    } 
    // we have to compute 4^5; binary equivalent of 5 is 0101 which means we can write 4^5 as 4^4 * 4^1.
    // time complexity - O(log n)
      
    public static void main(String args[] ) {
        Scanner in=new Scanner(System.in);
        int a = in.nextInt();
        int x = in.nextInt();
        System.out.println("Value is: "+iterative_power(a,x));
    }
}
