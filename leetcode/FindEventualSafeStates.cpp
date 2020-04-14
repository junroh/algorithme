// https://leetcode.com/problems/find-eventual-safe-states/
class Solution {
public:
    int* colors;
    // 0:non-visit, 1:in cycle, 2:out of cycle

    bool isCycle(int idx, vector<vector<int>>& graph) {
        colors[idx] = 1;    // visit and assume this is in cycle
        for(auto adj: graph[idx]) {
            if(colors[adj]==0 && isCycle(adj, graph) || colors[adj]==1)
                return true;
        }
        colors[idx] = 2;    // visited and this is not in cycle
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ret;
        colors = new int[graph.size()]();
        for(int i=0;i<graph.size();i++) {
            if(colors[i]==2 || !isCycle(i, graph))
                ret.push_back(i);
        }
        delete[] colors;
        return ret;
    }
};
