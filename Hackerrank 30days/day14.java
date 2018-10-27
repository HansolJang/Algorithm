import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;


class Difference {
  	private int[] elements;
  	public int maximumDifference;

    public Difference(int[] elements) {
        this.elements = elements;
    }

	private int abs(int a) {
        return a < 0 ? a * (-1) : a;
    }

    private int max(int a, int b) {
        return a > b ? a : b;
    }

    public void computeDifference() {
        int size = elements.length;
        for(int i = 0; i < size - 1; i++) {
            for(int j = i + 1; j < size; j++) {
                maximumDifference = max(maximumDifference, abs(elements[i] - elements[j]));
            }
        }
    }

} // End of Difference class

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        sc.close();

        Difference difference = new Difference(a);

        difference.computeDifference();

        System.out.print(difference.maximumDifference);
    }
}