// https://leetcode.com/problems/find-the-town-judge/
// A little bit unclear on the problem
// 3 [[1,1],[1,1],[1,3],[2,3],[3,3]]
// Those two test cases should return -1 because 3 trusts 3 and this doesn't satisfy Everybody (except for the town judge) trusts the town judge
// However, code in leetcode says 3 is a judge.
// Current code can solve this issue but still duplicate path doesn't solve in here
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> in(N + 1, 0);
        vector<int> out(N + 1, 0);
        for ( auto x : trust) {
            out[x[1]]++;
            in[x[0]]++;
        }
        for (int i=1; i<N+1 ; i++ ) {
            if ( in[i]==0 && out[i]==N-1)
                return i;
        }
        return -1;
    }
};
