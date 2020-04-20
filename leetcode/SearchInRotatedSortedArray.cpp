// https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int e = nums.size()-1;
        int s = 0;
        while(s<=e) {
            int mid = (e+s)/2;
            int midVal = nums[mid];
            int startVal = nums[s];
            int endVal = nums[e];
            if(target==midVal)
                return mid;
            if(midVal<=endVal) { // right is sorted
                if(target > midVal && target <= endVal)
                    s = mid+1;
                else
                    e = mid-1;
            } else { // left is sorted
                if (target < midVal && target >= startVal)
                    e = mid-1;
                else 
                    s = mid+1;
            }
        }
        return -1;
    }
};
