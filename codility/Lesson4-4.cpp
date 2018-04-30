vector<int> solution(int N, vector<int> &A) {
    vector<int> ret(N,0);
    int maxcnt=0;
    int basenum=0;
    for(int i=0;i<A.size();i++){
        if(A[i]<=N){
            ret[A[i]-1] = (basenum>ret[A[i]-1])?basenum:ret[A[i]-1];
            ++ret[A[i]-1];
            if(ret[A[i]-1]>maxcnt)
                maxcnt=ret[A[i]-1];
        }
        else
            basenum=maxcnt;
    }
    for(int i=0;i<N;i++){
        if(ret[i]<basenum)
            ret[i]=basenum;
    }
    return ret;
}
