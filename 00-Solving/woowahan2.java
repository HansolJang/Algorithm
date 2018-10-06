class Solution {

    public int solution(String A, String B) {
        
        String card = "AKQJT98765432";
        
        int len = A.length();
        int result = 0;
        for(int i = 0; i < len; i++) {
            if(card.indexOf(A.charAt(i)) < card.indexOf(B.charAt(i))) result++;
        }
        return result;
    }
}