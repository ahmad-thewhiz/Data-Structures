import java.util.*;

class Main {

    static long computing_power(int a, int x) {
        if(x==0)
            return 1;
        long temp = computing_power(a,x/2);
        temp = temp*temp;
        if(x%2==0)
            return temp;
        else
            return temp*a;
    } // time complexity - theta(log n)

    public static void main(String args[] ) {
        Scanner in=new Scanner(System.in);
        int a = in.nextInt();
        int x = in.nextInt();
        System.out.println("Value is: "+computing_power(a,x));
    }
}