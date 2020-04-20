// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3299/
// Perform String Shifts
class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int move = 0;
        for(auto ss:shift) {
            int dir = ss[0]==1?1:-1;
            dir *= ss[1];
            move += dir;            
        }
        if(move>0) {
            move = move%s.size();
            move = s.size() - move;
        } else {
            move = ((-move)%s.size());
        }

        string ret;
        for(int i=move;i<s.size();i++)
            ret.push_back(s[i]);
        for(int i=0;i<move;i++)
            ret.push_back(s[i]);
        return ret;
    }
};
