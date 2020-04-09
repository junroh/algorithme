// https://leetcode.com/problems/intersection-of-two-arrays/
class Solution {
public:
    void set_intersection(unordered_set<int>& n1, unordered_set<int>& n2, vector<int>& ret) {
        unordered_set<int>::iterator it;
        for(it=n1.begin();it!=n1.end();it++) {
            if(n2.find(*it)!=n2.end()) 
                ret.push_back(*it);
        }
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1;
        for(int i=0;i<nums1.size();i++)
            n1.insert(nums1[i]);
        unordered_set<int> n2;
        for(int i=0;i<nums2.size();i++)
            n2.insert(nums2[i]);
        
        vector<int> ret;
        if(n1.size()>n2.size())
            set_intersection(n1,n2,ret);
        else
            set_intersection(n2,n1,ret);
        return ret;
    }
};
