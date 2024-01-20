import java.util.*;
import java.lang.Math;

class Main {

    static int lcm(int a, int b) {
        int max = Math.max(a,b);
        while(true) {
            if(max%a==0 && max%b==0)
                return max;
            max++;
        }
    }
    
    static int gcd_optimized(int a, int b) {
        if(b==0)
            return a;
        return gcd_optimized(b,a%b);
    }
    
    static int lcm_optimized(int a, int b) {
        return (a*b)/gcd_optimized(a,b);
    }

    public static void main(String args[]) {
        Scanner in=new Scanner(System.in);
        int a=in.nextInt();
        int b=in.nextInt();
        System.out.println("LCM: "+lcm(a,b));
        System.out.println("LCM: "+lcm_optimized(a,b));
    }
}