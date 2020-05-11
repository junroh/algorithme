// https://leetcode.com/problems/valid-perfect-square/
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1, right = num;
        while (left <= right) {
            int mid = left + (right - left) / 2; 
            int res = num / mid;
            int remain = num % mid;
            if (res == mid && remain == 0) 
                return true;
            if (res > mid)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};
