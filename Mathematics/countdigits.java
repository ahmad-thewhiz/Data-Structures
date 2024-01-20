#import java.util.*;

class countdigits {

    static int digisum(int n) {
        int count=0;
        for(int i=n;i>0;i=i/10)
            count++;
        return count;
    }

    public static void main(String args[]) {
        Scanner in=new Scanner(System.in);
        int num=in.nextInt();
        System.out.println("Number of digits: "+digisum(n));
    }
}