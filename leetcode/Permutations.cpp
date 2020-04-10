// https://leetcode.com/problems/permutations/
class Solution {
    vector<vector<int>> ret;
public:
    void findPerm(vector<int>& nums, vector<int>& perm, bool* visit) {
        if(perm.size() == nums.size()) {
            ret.push_back(perm);
            return;
        }

        for(int i=0;i<nums.size();i++) {
            if(!visit[i]) {
                perm.push_back(nums[i]);
                visit[i]=true;
                findPerm(nums,perm,visit);                
                visit[i]=false;
                perm.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        bool* visit = new bool[nums.size()]{false,};
        vector<int> perm;
        findPerm(nums,perm,visit);
        delete[] visit;
        return ret;
    }
};
