int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int max_gap=0;
    int cur_pos=0;
    while(!(N&0x01))
        N >>= 1;
    while(N){
        if(N&0x01){
            if(max_gap<cur_pos)
                max_gap = cur_pos;
            cur_pos=0;    
        }
        else
            ++cur_pos;
        N >>= 1;
    }
    return max_gap;
}
