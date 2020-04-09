//https://leetcode.com/problems/add-binary/
class Solution {
public:
    long bin2dec(string& bin) {
        long val = 0;
        int len=bin.length();
        for(int i=0;i<len;i++) {
            val += ((long)(bin[(len-1)-i] - '0')<<i);
        }
        return val;
    }
    
    string dec2bin(long dec) {
        if(dec==0) {
            return "0";
        }
        string bin;
        while(dec>0) {
            bin += (dec&0x01) + '0';
            dec = (dec>>1);
        }
        reverse(bin.begin(), bin.end());
        return bin;
    }

    // this is not working with long binary value 
    // because this is relying on long type.
    string addBinaryConv(string& a, string& b) {
        long la=bin2dec(a);
        long lb=bin2dec(b);
        return dec2bin(la+lb);
    }
    
    string addBinaryDir(string& a, string& b) {
        string str;
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        while(i >= 0 || j >= 0){
            int sum = carry;
            if(i >= 0) { 
                sum += a[i] - '0';
            }
            if(j >= 0) {
                sum += b[j] - '0';
            }
            str += ((sum&0x01)+'0');
            carry = sum>>1;
            i--;
            j--;
        }
        if(carry != 0)
            str += (carry +'0');
        reverse(str.begin(), str.end());
        return str;
    }

    string addBinary(string a, string b) {
        return addBinaryDir(a,b);
    }
};
