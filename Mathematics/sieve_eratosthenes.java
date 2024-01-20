import java.util.*;

class Main {

    // prints all the prime numbers between 1 and n
    static void sieve_eratosthenes(int num) {
        boolean isPrime[] = new boolean[num+1];
        Arrays.fill(isPrime, true);
        for(int i=2;i*i<=num;i++) {
            if(isPrime[i]) {
                for(int j=i*2;j<=num;j=j+i)
                    isPrime[j]=false;
            }
        }
        for(int i=2;i<=num;i++) 
            if(isPrime[i])
                System.out.println(i);
    }

    static void sieve_eratosthenes_optimized(int num) {
        boolean isPrime[] = new boolean[num+1];
        Arrays.fill(isPrime, true);
        for(int i=2;i<=num;i++) {
            if(isPrime[i]) {
                System.out.println(i);
                for(int j=i*i;j<=num;j=j+i) // here we are using i^2 because factors of i before i^2 will have been covered by numbers less than i 
                    isPrime[j]=false;
            }
        }
    }

    public static void main(String args[] ) {
        Scanner in=new Scanner(System.in);
        int num = in.nextInt();
        sieve_eratosthenes(num);
        sieve_eratosthenes_optimized(num);
    }
}