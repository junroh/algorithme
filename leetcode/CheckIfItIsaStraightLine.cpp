//https://leetcode.com/problems/check-if-it-is-a-straight-line/
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        auto a = coordinates[0];
        auto b = coordinates[1];
        int x1 = a[0];
        int x2 = b[0];
        int y1 = a[1];
        int y2 = b[1];

        for (int i = 2; i < coordinates.size(); i++) {
          auto curr = coordinates[i];
          int x3 = curr[0];
          int y3 = curr[1];
          if((y2 - y1)*(x3 - x1) != (y3 - y1)*(x2 - x1)) 
              return false;
        }
        return true;
    }
};
