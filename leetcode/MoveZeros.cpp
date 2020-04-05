// https://leetcode.com/problems/move-zeroes/
class Solution {
public:
    void sol1(vector<int>& nums) {
        int n=nums.size();
        int nonZeroCnt=0;
        for(int i=0;i<n;i++) {
            if(nums[i]!=0)
                nums[nonZeroCnt++] = nums[i];
        }
        for(int i=nonZeroCnt;i<n;i++)
            nums[i] = 0;        
    }
    
    void sol2(vector<int>& nums) {
        int nonZeroCnt=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]!=0)
                swap(nums[nonZeroCnt++], nums[i]);
        }
    }
    
    void moveZeroes(vector<int>& nums) {
        sol2(nums);
    }
}
