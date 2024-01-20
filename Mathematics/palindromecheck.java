import java.util.*;

class Main {

    static boolean palindromcheck(int num) {
        int rev=0,dig;
        for(int i=num;i>0;i=i/10) {
            dig=i%10;
            rev=rev*10+dig;
        }
        return (num==rev);
    }

    public static void main(String args[]) {
        Scanner in=new Scanner(System.in);
        int num=in.nextInt();
        if(palindromcheck(num))
            System.out.println("Yes, the number is palindrome");
        else
            System.out.println("No, the number is not palidrome");
    }
}