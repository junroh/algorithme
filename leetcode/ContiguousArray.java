// https://leetcode.com/problems/contiguous-array/
class Solution {
public:
    int bf(vector<int>& nums) {
        int n = nums.size();
        int ret = 0;
        int zeros = 0;
        int ones = 0;
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                if(nums[j]==0)  zeros++;
                else            ones++;
                if(zeros==ones) {
                    ret = max(ret, j-i+1);
                }
            }
        }
        return ret;        
    }
    
    int optimisation(vector<int>& nums) {
        unordered_map<int,int> map;
        int maxlen=0;
        int sum=0;
        for(int i=0;i<nums.size();i++) {
            sum += (nums[i]==0?-1:1);
            if(sum==0)
                maxlen = i+1;
            else if(map.find(sum)==map.end())
                map[sum]=i;
            else
                maxlen = max(maxlen, i-map[sum]);
        }
        return maxlen;
    }
    
    int findMaxLength(vector<int>& nums) {
        return optimisation(nums);
    }
};
