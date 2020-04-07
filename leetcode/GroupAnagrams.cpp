// https://leetcode.com/problems/group-anagrams/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > occur; 
        for(int i=0;i<strs.size();i++) {
            string str = strs[i];
            string conv;
            if(false) {
                char count[26] = {0,};
                for(int j=0;j<str.size();j++) {
                    count[str[j]-'a']++;
                }
                for(int j=0;j<26;j++) {
                    conv += (count[j]+'0');
                }
            } else {
                conv = str;
                sort(conv.begin(), conv.end()); 
            }
            occur[conv].push_back(str);
        }

        vector<vector<string>> ret;
        unordered_map<string, vector<string>>::iterator it;
        for(it=occur.begin();it!=occur.end();it++) {
            ret.push_back(it->second);
        }
        return ret;
    }
};
