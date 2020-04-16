// https://leetcode.com/problems/valid-parenthesis-string/
class Solution {
public:
    bool checkValidString(string s) {
        stack<char> stackOpen;
        stack<char> stackStar;
        for(int i=0; i<s.size(); i++) {
            char c=s[i];
            if(c==')') {
                if(stackOpen.empty()) {
                    if(stackStar.empty())   return false;
                    stackStar.pop();
                } else {
                    stackOpen.pop();
                }
            } else if(c=='(') {
                stackOpen.push(i);
            } else if(c=='*') {
                stackStar.push(i);
            } else {
                return false;
            }
        }
        while(!stackOpen.empty() && !stackStar.empty()) {
            if (stackStar.top() < stackOpen.top())    return false;
            stackStar.pop();
            stackOpen.pop();
        }
        return stackOpen.empty();
    }
};
