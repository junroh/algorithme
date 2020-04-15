// https://leetcode.com/problems/product-of-array-except-self/
class Solution {
public:
    vector<int> sol1(vector<int>& nums) {
        vector<int> rlt;
        int* t1 = new int[nums.size()];
        int* t2 = new int[nums.size()];
        t1[0]=1;
        for(int i=0; i<nums.size()-1;i++)
            t1[i+1] = t1[i] * nums[i];
        t2[nums.size()-1]=1;
        for(int i=nums.size()-1; i>0; i--)
            t2[i-1]= t2[i] * nums[i];
        for(int i=0;i<nums.size();i++)
            rlt.push_back(t1[i]*t2[i]);
        delete[] t1;
        delete[] t2;
        return rlt;
    }
    
    vector<int> sol2(vector<int>& nums) {
        vector<int> rlt;
        int prod=1;
        for(int i=0; i<nums.size(); i++) {
            rlt.push_back(prod);
            prod *= nums[i];
        }
        prod=1;
        for(int i=nums.size()-1; i>=0; i--) {
            rlt[i] *= prod;
            prod *= nums[i];
        }

        return rlt;
    }

    vector<int> productExceptSelf(vector<int>& nums) {
        return sol2(nums);
    }
};
