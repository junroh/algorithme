// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3313
/*
 * Input:
 * ["FirstUnique","showFirstUnique","add","showFirstUnique","add","showFirstUnique","add","showFirstUnique"]
 * [[[2,3,5]],[],[5],[],[2],[],[3],[]]
 * Output:
 * [null,2,null,2,null,3,null,-1]
 */
class FirstUnique {
    list<int> uniq;
    unordered_map<int, list<int>::iterator> m;
public:
    FirstUnique(vector<int>& nums) {
        for(int n:nums) {
            add(n);
        }
    }
    
    int showFirstUnique() {
        int ret = -1;
        if(!uniq.empty())
            ret = uniq.back();
        return ret;
    }
    
    void add(int value) {
        auto it = m.find(value);
        if(it==m.end()) {
            uniq.push_front(value);
            m[value] = uniq.begin();
        } else if(m[value]!=uniq.end()) {
            uniq.erase(m[value]);
            m[value] = uniq.end();
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */

