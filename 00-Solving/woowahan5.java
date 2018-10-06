// you can also use imports, for example:
//import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    
    private static final int ERROR = -1;
    
    private int[] apples;
    
    public int solution(int[] A, int K, int L) {
        apples = A;
        int length = apples.length;
        if(K + L > length) return ERROR;
    
        int result = ERROR;
        for(int i = 0; i < length; i++) {
            int alice = getApples(i, K);
            if(alice < 0) continue;
            for(int j = 0; j < length; j++) {
                // out of range
                if((j >= i && j < i + K) 
                    || (j + L - 1 >= i && j + L - 1 < i + K)) continue;
                int bob = getApples(j, L);
                if(bob < 0) continue;
                else result = Math.max(result, alice + bob);
            }   
        }
        return result;
    }
    
    private int getApples(int start, int num) {
        if(start + num > apples.length) return ERROR;
        int result = 0;
        for(int i = start; i < start + num; i++) {
            result += apples[i];
        }
        return result;
    }
}