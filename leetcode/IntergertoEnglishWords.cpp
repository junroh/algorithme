// https://leetcode.com/problems/integer-to-english-words/
class Solution {
    string ones[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string thousands[4] = {"", " Thousand", " Million", " Billion"};

public:
    string numberToWords(int num) {
        if(num<0) return "";
        if(num==0) return "Zero";
        string str;
        buildString(str, num, 0, num/1000>0);
        return str;
    }
    
    void buildString(string& str, int num, int idx, bool hasMore) {
        if(hasMore) {
            buildString(str, num/1000, idx+1, num/1000 > 0);
        }

        num = num%1000;
        if(num > 0) {
            parseNum(num, str);
            str += thousands[idx];
        }
    }
    
    void parseNum(int num, string& str) {
        if(num == 0) return;        
        if(!str.empty()) str += " ";

        if(num<20) {
            str += ones[num];
        } else if(num<100) {
            str += tens[num/10];
            parseNum(num%10, str);
        } else {
            str += ones[num/100];
            str += " Hundred";
            parseNum(num%100, str);
        }
    }
};
