int solution(vector<int> &A) {
    int sum=0;
    for(size_t i=0; i<A.size(); ++i)
        sum += A[i];
    return ((A.size()+1)*(A.size()+2))/2 - sum;
}
