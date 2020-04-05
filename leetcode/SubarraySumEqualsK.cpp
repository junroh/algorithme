//https://leetcode.com/problems/subarray-sum-equals-k/solution/
class Solution {
public:
    int bf(vector<int>& nums, int k) {
        int n=nums.size();
        int ret = 0;
        for(int i=0;i<n;i++) {
            int sum=0;
            for(int j=i;j<n;j++) {
                sum += nums[j];
                if(sum==k)  ret++;
            }
        }
        return ret;
    }
    
    int dp(vector<int>& nums, int k) {
        int sum=0;
        int ret=0;
        unordered_map<int, int> sumCnt;
        int n=nums.size();
        for (int i=0;i<n;i++) {
            sum += nums[i];
            if(sum==k) ret++;
            if (sumCnt.find(sum - k) != sumCnt.end()) 
                ret += (sumCnt[sum - k]); 
            sumCnt[sum]++; 
        }
        return ret;
    }

    int subarraySum(vector<int>& nums, int k) {
        return dp(nums,k);
    }
}
