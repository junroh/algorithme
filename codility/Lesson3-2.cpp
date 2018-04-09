int solution(int X, int Y, int D) {
    if(X >= Y)
        return 0;
    int dist = Y - X;
    return (dist+D-1)/D;
}
