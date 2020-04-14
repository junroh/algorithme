// https://leetcode.com/problems/is-graph-bipartite/
class Solution {
public:
    int* colors;     // red=1, blue=-1
    vector<vector<int>> graph;

    bool dfs(int v, int color) {
        colors[v]=color;
        vector<int> vertices = graph[v];
        for(int i=0;i<vertices.size();i++) {
            int tmp=vertices[i];
            if(colors[tmp]==0) {
                if(!dfs(tmp, -color)) {
                    return false;
                }
            } else if(colors[tmp]==color) {
                return false;
            }
        }
        return true;
    }
    
    bool bfs(int start, int color) {
        queue<int> q;
        colors[start]=color;
        q.push(start);
        while(!q.empty()) {
            int vertix = q.front();
            q.pop();
            for(auto v:graph[vertix]) {
                if(colors[v]==0) {
                    q.push(v);
                    colors[v] = -colors[vertix];
                } else {
                    if(colors[v]==colors[vertix])
                        return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        this->graph = graph;
        colors = new int[graph.size()]();
        bool ret=true;
        for(int s=0; s<this->graph.size() && ret==true;s++) {
            if (colors[s] == 0)
                ret=bfs(s,1);
        }
        delete[] colors;
        return ret;
    }
};
