#include <cstdlib>
int solution(vector<int> &A) {
    vector<int> B = A;
    B[0]=A[0];
    for(int i=1; i<A.size(); ++i)
        B[i] = A[i] + B[i-1];
    int sum=B[B.size()-1];
    int min=0xFFFFFFFF/2;
    for(int i=0;i<A.size()-1; ++i){
        int val = abs(B[i] - (sum-B[i]));
        if(val<min)
            min=val;
    }
    return min;
}
