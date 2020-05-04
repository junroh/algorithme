//https://leetcode.com/problems/number-complement/

class Solution {
public:
    int sol1(int num) {
        int ret=0;
        int i=0;
        while(num>0) {
            int comp = ~(num&0x01);
            ret |= ((comp&0x01)<<i);
            num >>= 1;
            i++;
        }
        return ret;
    }

    int sol2(int num) {
        int tmp = num;
        int mask=0;
        while(tmp>0) {
            tmp >>= 1;
            mask <<= 1;
            mask |= 1;
        }
        return (~num) & mask;
    }

    int findComplement(int num) {
        return sol2(num);
    }
};
