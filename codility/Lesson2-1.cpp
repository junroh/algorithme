vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> B = A;
    for(int i=0; i< A.size(); ++i){
        int tgt = (i+K)%A.size();
        B[tgt]=A[i];
    }
    return B;
}
