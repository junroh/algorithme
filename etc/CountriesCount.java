// Codility - Countires count
// This is from Grakn
// https://github.com/lekaha/coding_practice/blob/master/codility/countries_count.py
class Solution {
    private static final int filled = 1000000001;

    void fill(int[][] map, int row, int col, int color) {
        if(row<0 || row>map.length-1 || col<0 || col>map[row].length-1) {
            return;
        }
        if(map[row][col]!=color) {
            return;
        }
        map[row][col] = filled;
        fill(map,row+1, col, color);
        fill(map,row-1, col, color);
        fill(map,row, col+1, color);
        fill(map,row, col-1, color);
    }
    
    public int solution(int[][] A) {
        int ret = 0;
        for(int r=0;r<A.length;r++) {
            for(int c=0;c<A[r].length;c++) {
                if(A[r][c]!=filled) {
                    fill(A,r,c,A[r][c]);
                    ret++;
                }
            }
        }
        return ret;
    }
}

