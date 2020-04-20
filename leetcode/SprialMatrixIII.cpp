// https://leetcode.com/problems/spiral-matrix-iii/
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int maxNum = R*C;
        int dirR[] = {0,1,0,-1};
        int dirC[] = {1,0,-1,0};

        int nextR = r0;
        int nextC = c0;
        int curNum=1;
        vector<vector<int>> ret;
        vector<int> pos = {nextR, nextC};
        ret.push_back(pos);

        int rot=0;
        int len=1;
        while(curNum<maxNum) {
            for(int dir=0;dir<4;dir++) {
                for(int i=0;i<len;i++) {
                    nextR += dirR[dir];
                    nextC += dirC[dir];
                    if(nextR>=0 && nextR<R && nextC>=0 && nextC<C){
                        pos[0] = nextR;
                        pos[1] = nextC;
                        ret.push_back(pos);
                        curNum++;
                    }
                }
                if(++rot==2) {
                    rot=0;
                    len++;
                }
            }
        }

        return ret;
    }
};
