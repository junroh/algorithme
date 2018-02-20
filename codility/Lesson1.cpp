int solution(int N) {
    int bin_gap = 1;
    int cur_pos = 0;
    int last_pos = -1;
    while(N>0){
        if((N&0x01)){
            if(last_pos >= 0 && cur_pos - last_pos > bin_gap)
                bin_gap = cur_pos - last_pos;
            last_pos = cur_pos;
        }
        cur_pos++;
        N = N >> 1;
    }
    bin_gap--;
    return bin_gap;
}