//https://leetcode.com/problems/basic-calculator-ii/
class Solution {
    private void opr(Stack<Integer> stack, char op, int num) {
        switch(op) {
            case '+':
                stack.push(num);
                break;
            case '-':
                stack.push(num*(-1));
                break;
            case '*':
                stack.push(stack.pop()*num);
                break;
            case '/':
                stack.push(stack.pop()/num);
                break;
        }
    }

    public int calculate(String s) {
        Stack<Integer> stack = new Stack<>();
        char[] ss = s.toCharArray();
        int num=0;
        char op='+';
        for(int i=0;i<ss.length;i++) {
            char c = ss[i];
            if(c==' ' ) continue;
            if(c-'0' >=0 && c-'0'<=9) {
                num = (num * 10) + c - '0';
            } else {
                opr(stack, op, num);
                op = c;
                num = 0;
            }
        }
        if(num!=0) {
            opr(stack,op, num);
        }
        int ret = 0;
        for(Integer n: stack) {
            ret += n;
        }
        return ret;
    }
}
}
