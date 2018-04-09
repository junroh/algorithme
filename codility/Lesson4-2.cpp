int solution(int X, vector<int> &A) {
    int* pchk = new int[X];
    for(int i=0; i<X; ++i)
        pchk[i] = 0;
    int leaf_cnt = 0;
    size_t i=0;
    for(i=0; i<A.size() ; ++i){
        if(!pchk[A[i]-1]){
            if(++leaf_cnt == X)
                break;
            pchk[A[i]-1] = 1;
        }
    }
    delete[] pchk;
    if(leaf_cnt == X)
        return i;
    return -1;
}
