class Solution {
    public int solution(int A, int B, int C, int D) {
        int result = 0;
        result = Math.max(result, square(A - C) + square(B - D));
        result = Math.max(result, square(A - D) + square(B - C));
        result = Math.max(result, square(A - B) + square(C - D));
        return result;
    }
    
    private int square(int num) {
        return num * num;
    }
}