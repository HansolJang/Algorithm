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
        int N = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        List<String> names = new ArrayList<String>();

        for (int NItr = 0; NItr < N; NItr++) {
            String[] firstNameEmailID = scanner.nextLine().split(" ");
            String firstName = firstNameEmailID[0];
            String emailID = firstNameEmailID[1];

            boolean result = Pattern.matches("^[a-z]{1,20}$", firstName);
            result &= Pattern.matches("^[a-z.]+@gmail.com{1,50}$", emailID);
            if(result) names.add(firstName);
        }

        scanner.close();

        Collections.sort(names);

        for(String name : names) {
            System.out.println(name);
        }
    }
}
