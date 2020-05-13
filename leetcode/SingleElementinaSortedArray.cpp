//https://leetcode.com/problems/single-element-in-a-sorted-array/
class Solution {
public:
    int linearSearch(vector<int>& nums) {
        if((nums.size()&0x01)==0)
            return -1;

        int i=0;
        while(i+2<nums.size()) {
            if(nums[i]!=nums[i+1]) {
                if(nums[i+1]==nums[i+2])    
                    return nums[i];
            } 
            i+=2;
        }
        return nums[i];
    }
    
    int binSearch(vector<int>& nums) {
        int e=nums.size()-1;
        int s=0;
        int m;
        while(s<e) {
            m=s+(e-s)/2;
            if( (!(m&0x01) && nums[m]==nums[m+1]) || 
               ((m&0x01) && nums[m]==nums[m-1]) )
                s = m + 1;
            else
                e = m;
        }
        return nums[s];
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        return binSearch(nums);
    }
};
