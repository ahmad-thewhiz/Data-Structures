import java.util.*;

class Main {

    static int gcd(int a, int b) {
        while(a!=b) {
            if(a>b)
                a=a-b;
            else
                b=b-a;
        }
        return a;
    }

    static int gcd_optimized(int a, int b) {
        if(b==0)
            return a;
        return gcd_optimized(b,a%b);
    }

    public static void main(String args[]) {
        Scanner in=new Scanner(System.in);
        int a=in.nextInt();
        int b=in.nextInt();
        System.out.println("GCD: "+gcd(a,b));
        System.out.println("GCD: "+gcd_optimized(a,b));
    }
}