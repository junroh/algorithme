// https://leetcode.com/problems/backspace-string-compare/
class Solution {
public:
    bool usingStack(string S, string T) {
        stack<char> s;
        stack<char> t;
        for(int i=0;i<S.size();i++) {
            if(S[i]=='#') {
                if(!s.empty())  s.påop();
            } else {
                s.push(S[i]);
            }
        }
        for(int i=0;i<T.size();i++) {
            if(T[i]=='#') {
                if(!t.empty())   t.pop();
            } else {
                t.push(T[i]);
            }
        }
        if(s.size()!=t.size())  return false;
        for(int i=0;i<s.size();i++) {
            if(s.top()!=t.top())    return false;
            s.pop();
            t.pop();
        }
        return true;        
    }
    
    bool usingCounting(string S, string T) {
        int s=S.size()-1;
        int t=T.size()-1;
        while(s>=0 || t>=0) {
            int count=0;
            while(s>=0) {
                if(S[s]=='#') {
                    s--;
                    count++;
                } else if(count>0) {
                    s--;
                    count--;
                } else {
                    break;
                }
            }
            count=0;
            while(t>=0) {
                if(T[t]=='#') {
                    t--;
                    count++;
                } else if(count>0) {
                    t--;
                    count--;
                } else {
                    break;
                }
            }
            if(s>=0 && t>=0 && S[s]!=T[t])  return false;
            if ((s >= 0) != (t >= 0))   return false;
            s--;
            t--;
        }
        return true;
    }
    
    bool backspaceCompare(string S, string T) {
        return usingCounting(S,T);
    }
};
