// https://leetcode.com/problems/longest-common-subsequence/
class Solution {
public:
    int bf(string& text1, string& text2, int pos1, int pos2) {
	    if (pos1==text1.size() || pos2 == text2.size()) 
            return 0;
	    else if (text1[pos1] == text2[pos2]) 
            return 1 + bf(text1, text2, ++pos1, ++pos2);
	    else return max(bf(text1, text2, ++pos1, pos2), bf(text1, text2, pos1, ++pos2));
    }
    
    int dp(string text1, string text2) {
        int** lcs = new int*[text1.size()+1];
        for(int i=0; i<text1.size()+1; i++)
            lcs[i]=new int[text2.size()+1];

        for(int i=0;i<=text1.size();i++) {
            for(int j=0;j<=text2.size();j++) {
                if(i==0|| j==0)
                    lcs[i][j]=0;
                else if(text1[i-1]==text2[j-1])
                    lcs[i][j]=1+lcs[i-1][j-1];
                else
                    lcs[i][j]=max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
        int ret = lcs[text1.size()][text2.size()];
        for(int i=0; i<text1.size()+1; i++)
            delete[] lcs[i];
        delete[] lcs;
        return ret;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        //return bf(text1,text2,0,0);
        return dp(text1,text2);
    }
};
