//https://leetcode.com/problems/maximum-subarray/
class Solution {

    private int bruteForce(int[] nums) {
        int max = 0;
        for(int i=0;i<nums.length;i++) {
            int sum=0;
            for(int j=i;j<nums.length;j++) {
                sum += nums[j];
                if(sum>max) {
                    max = sum;
                }
            }
        }
        return max;
    }
    
    private int dynamicProgramming(int[] nums){
        int max = Integer.MIN_VALUE;
        int localMax = 0;
        for(int i=0;i<nums.length;i++) {
            int localSum = nums[i]+localMax;
            if(localSum > nums[i])
                localMax = localSum;
            else
                localMax = nums[i];
            if(localMax > max)
                max = localMax;
        }
        return max;
    }
    
    public int maxSubArray(int[] nums) {
        return dynamicProgramming(nums);
    }
}

