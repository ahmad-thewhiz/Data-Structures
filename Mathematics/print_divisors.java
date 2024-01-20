import java.util.*;

class Main {

    static void print_divisors(int num) {
        int i;
        for(i=1;i*i<=num;i++)
            if(num%i==0)
                System.out.println(i);
        for( ;i>=1;i--)
            if(num%i==0)
                System.out.println(num/i);
    }

    public static void main(String args[] ) {
        Scanner in=new Scanner(System.in);
        int num = in.nextInt();
        print_divisors(num);
    }
}