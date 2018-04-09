int solution(vector<int> &A) {
    int sum_exp = 0;
    int sum_A = 0;
    int* pchk = new int[A.size()+1];
    for(size_t i=0; i<A.size(); ++i){
        sum_exp += (i+1);
        sum_A += A[i];
        pchk[i] = 0;
    }
    pchk[A.size()] = 0;
    if(sum_exp != sum_A){
        delete[] pchk;
        return 0;
    }
    int ret=1;
    for(size_t i=0;i<A.size(); ++i){
        if(pchk[A[i]]){
            ret=0;
            break;
        }
        pchk[A[i]]=1;
    }
    delete[] pchk;
    return ret;
}
