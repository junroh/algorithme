// https://leetcode.com/problems/first-unique-character-in-a-string/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> pos;
        for(char c: s)
            pos[c]++;
        for(int i=0;i<s.size();i++)
            if(pos[s[i]]==1)   return i;
        return -1;
    }
};
