import java.util.*;

class Main {

    static long factorial(int num) {
        if(num==0)
            return 1;
        return num*factorial(num-1);
    }

    static int trailing_zeros(int num) {
        long fact = factorial(num);
        int count =0;
        while(fact%10==0) {
            count++;
            fact=fact/10;
        } 
        return count;
    }// Time complexity - theta(n)

    static int trailing_zeros_efficient(int num) {
        int count=0;
        for(int i=5;i<=num;i=i*5) {
            count = count + num/i;
        }
        return count;
    }//time complexity - theta(log n)
    // logic in this function is to find number of 5s present in the prime factorization of that number, since 5*2=10 with a trailing 0 also number of 2s are greater than number of 5s.

    public static void main(String args[]) {
        Scanner in=new Scanner(System.in);
        int num=in.nextInt();
        System.out.println("Factorial: "+factorial(num));
        System.out.println("Trailing Zeros: "+trailing_zeros(num));
        System.out.println("Trailing Zeros: "+trailing_zeros_efficient(num));
    }
}

