//https://leetcode.com/problems/clumsy-factorial/
class Solution {
public:    
    int clumsy(int N) {
        if(N<1) {
            return N;
        }

        stack<int> s;
        s.push(N);
        int opr=0;
        while(--N!=0) {
            switch(opr) {
                case 0: s.top() *= N; break;
                case 1: s.top() /= N; break;
                case 2: s.push(N); break;
                case 3: s.push(-N); break;
            }
            opr = (opr+1)%4;
        }
        int ret = 0;
        while (!s.empty()) {
            ret += s.top();
            s.pop();
        }
        return ret;
    }
};
