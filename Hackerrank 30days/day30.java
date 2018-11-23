import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {



    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            String[] nk = scanner.nextLine().split(" ");

            int n = Integer.parseInt(nk[0]);
            int k = Integer.parseInt(nk[1]);

            int ans = 0;
            int temp = 0;
            for(int i = 1; i < n; i++) {
                for(int j = i + 1; j <= n; j++) {
                    temp = i & j;
                    if(ans < temp && temp < k) {
                        ans = temp;
                    }
                }
            }
            System.out.println(ans);
        }

        scanner.close();
    }
}
