import java.util.*;

class Main {

    static long factorial(int num) {
        if(num==0)
            return 1;
        return num*factorial(num-1);
    }

    public static void main(String args[]) {
        Scanner in=new Scanner(System.in);
        int num=in.nextInt();
        System.out.println("Factorial: "+factorial(num));
    }
}