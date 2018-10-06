import java.util.*;

class Solution {
    
    private final static int ERROR = -1;
    
    Stack<Integer> stack = new Stack<>();
    
    public int solution(String S) {
        String operations[] = S.split(" ");
        
        for(String oper : operations) {
            if(oper.equals("DUP")) {
                if(stack.isEmpty()) return ERROR;
                else stack.push(stack.peek());
            } else if(oper.equals("POP")) {
                if(stack.isEmpty()) return ERROR;
                else stack.pop();
            } else if(oper.equals("+")) {
                if(stack.size() < 2) return ERROR;
                else stack.push(stack.pop() + stack.pop());
            } else if(oper.equals("-")) {
                if(stack.size() < 2) return ERROR;
                else stack.push(stack.pop() - stack.pop());
                if(stack.peek() < 0) return ERROR;
            } else {
                int num = Integer.parseInt(oper);
                stack.push(num);
            }
        }
        
        if(stack.isEmpty()) return ERROR;
        else return stack.peek();
    }
}