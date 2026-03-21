class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int l=x, h=x+k-1;
        int p=y, q=y+k-1;

        while(l<h){
            for(int i=p; i<=q; i++){
                swap(grid[l][i],grid[h][i]);
            }
            l++;
            h--;
        }

        return grid;
    }
};