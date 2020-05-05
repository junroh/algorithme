//https://leetcode.com/problems/ransom-note/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> chars;
        for(char c: magazine)
            chars[c]++;
        for(char c: ransomNote)
            if(chars[c]--==0) 
                return false;
        return true;
    }
};
