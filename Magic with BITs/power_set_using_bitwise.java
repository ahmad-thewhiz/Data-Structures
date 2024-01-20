// Bit-Handling -- Power Set using Bitwise

import java.util.*;

public class Main {
    public static void printPowerSet(String str) {
        int n = str.length();
        int pSize = (1<<n); //2^n
        for(int i=0;i<pSize;i++) {
            for(int j=0;j<n;j++) {
                if((i&(1<<j))!=0)
                    System.out.print(str.charAt(j));
            }
            System.out.println();
        }
    }
    public static void main(String args[]) {
        Scanner in=new Scanner(System.in);
        String str = in.nextLine();
        printPowerSet(str);
    }
}