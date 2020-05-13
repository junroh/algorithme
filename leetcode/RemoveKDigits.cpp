//https://leetcode.com/problems/remove-k-digits/
class Solution {
    string minNum;
    int compareStr(string a, string b) {
        if(a.size()>b.size())
            return 1;
        else if(a.size()<b.size())
            return -1;
        for(int i=0;i<a.size();i++) {
            if(a[i]>b[i])   return 1;
            else if(a[i]<b[i])  return -1;
        }
        return 0;
    }
    string makeNumStr(string num) {
        int i=0;
        while(num[i]=='0')  i++;
        return (i==num.size())? "0": num.substr(i,num.size()-i);
    }
    void dfs(string num, string candidate, int cnt, int k) {
        int n = num.size();
        if(cnt==k || n==0) {
            if(candidate.size()==k) {
                string number = makeNumStr(candidate);
                if(compareStr(minNum,number)>0)   
                    minNum=number;
            }
            return;
        }
        dfs(num.substr(1, n-1), candidate+num[0], cnt+1, k);
        dfs(num.substr(1, n-1), candidate, cnt, k);
    }
    
    // using dfs. Check every cases. Timeout!
    string bf(string num, int k) {
        minNum = "";
        for(int i=0;i<10002;i++)
            minNum += "9";
        dfs(num, "", 0, num.size()-k);
        return minNum;        
    }
    
    // traverse number string and remove previous number if current number is smaller than previous one
    string optimal1(string num, int k) {
        stack<char> s;
        if(k == num.size()) 
            return "0";
        for(char c: num){
            while(k && !s.empty() && s.top() > c){
                k--;
                s.pop();
            }
            s.push(c);
        }
        while(k-- > 0) 
            s.pop();

        string sNum = "";
        while(!s.empty()) {
            printf("%c",s.top());
            sNum =  s.top() + sNum;
            s.pop();
        }
        int idx=0;
        while(sNum[idx]=='0')
            idx++;
        return (idx==sNum.size())? "0": sNum.substr(idx,sNum.size()-idx);
    }
    
    string optimal2(string num, int k) {
        string ans="";
        for(auto c:num){
            while(ans.length() && ans.back()>c && k){
                ans.pop_back();
                --k;
            }
            if(ans.length() || c!='0')
                ans+=c;
        }
        while(k--&&ans.length())
            ans.pop_back();
        return ans.length()?ans:"0";
    }

public:
    string removeKdigits(string num, int k) {
        return optimal2(num,k);
    }
};
