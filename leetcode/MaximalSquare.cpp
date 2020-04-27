// https://leetcode.com/problems/maximal-square/
class Solution {
public:
    int bf(vector<vector<char>>& matrix) {
        int rMax = matrix.size();
        int cMax = (rMax==0)?0:matrix[0].size();
        int maxSq = 0;
        for(int r=0;r<rMax;r++) {
            for(int c=0;c<cMax;c++) {
                if(matrix[r][c]=='0') continue;
                int sq = 1;
                bool filled = true;
                while(r+sq < rMax && c+sq < cMax && filled) {
                    for(int i=0;i<=sq;i++) {
                        if(matrix[r+sq][c+i]=='0') {
                            filled = false;
                            break;
                        }
                    }
                    for(int i=0;i<=sq;i++) {
                        if(matrix[r+i][c+sq]=='0') {
                            filled = false;
                            break;
                        }
                    }
                    if(filled) sq++;
                }
                maxSq = max(maxSq,sq);
            }
        }
        return maxSq*maxSq;        
    }
    
    int dp(vector<vector<char>>& matrix) {
        int rMax = matrix.size();
        int cMax = (rMax==0)?0:matrix[0].size();
        int maxSq = 0;
        int** dp = new int*[rMax+1]();
        for(int i=0;i<rMax+1;i++)
            dp[i] = new int[cMax+1]();

        for(int r=1;r<=rMax;r++) {
            for(int c=1;c<=cMax;c++) {
                if(matrix[r-1][c-1]=='1') {
                    dp[r][c] = min(min(dp[r-1][c-1], dp[r-1][c]), dp[r][c-1])+1;
                    maxSq = max(maxSq, dp[r][c]);
                }
            }
        }
        return maxSq*maxSq;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        return dp(matrix);
    }
};
