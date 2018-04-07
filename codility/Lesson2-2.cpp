int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int ret=0;
    for(int i=0; i<A.size(); ++i)
        ret = ret^A[i];
    return ret;
}
