// https://leetcode.com/problems/rotate-array/

class Solution {
    public void rotate(int[] nums, int k) {
        k=k%nums.length;
        sol3(nums, k);
    }
    
    // bruteforce - inplace update, o(nk)
    private void sol1(int[] nums, int k) {
        for(int i=0;i<k;i++) {
            int tmp = nums[nums.length-1];
            for(int j=nums.length-2;j>=0;j--) {
                nums[j+1] = nums[j];
            }
            nums[0] = tmp;
        }
    }
    
    // additional memory, o(n)
    private void sol2(int[] nums, int k) {
        int[] tmp = new int[nums.length];
        for(int i=0;i<=k;i++) {
            tmp[i+k]=nums[i];
        }
        for(int i=0;i<k;i++) {
            tmp[i]=nums[nums.length-k+i];
        }
        for(int i=0;i<nums.length;i++){
            nums[i]=tmp[i];            
        }
    }
    
    // inplace update, o(n)
    private void sol3(int[] nums, int k) {
        reverse(nums, 0, nums.length - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.length - 1);
    }
    private void reverse(int[] nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
}
