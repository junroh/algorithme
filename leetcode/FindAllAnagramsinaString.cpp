//https://leetcode.com/problems/find-all-anagrams-in-a-string/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int pm[26]={0,};
        for(char c:p)
            pm[c-'a']++;

        vector<int> ret;
        int we=0;
        int ws=0;
        while(we<s.length()) {
            int i=s[we]-'a';
            if(pm[i]>0) {
                pm[i]--;    we++;
                if(we-ws==p.length())   ret.push_back(ws);
            } else if(ws == we) {
                ws++;
                we++;
            } else {
                pm[s[ws]-'a']++;
                ws++;
            }  
        }
        return ret;
    }
};
