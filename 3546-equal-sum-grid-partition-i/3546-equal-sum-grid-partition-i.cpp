class Solution {
    using ll = long long;
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        ll n = grid.size();
        ll m = grid[0].size();
        ll totalSum = 0;
        vector<ll>rowSum(n), colSum(m);
        for(ll row = 0; row < n; row++){
            ll tempSum = 0;
            for(ll col = 0; col < m; col++){
                tempSum += grid[row][col];
            }
            rowSum[row] = tempSum;
            totalSum += tempSum;
        }
        for(ll col = 0; col < m; col++){
            ll tempSum = 0;
            for(ll row = 0; row < n; row++){
               tempSum += grid[row][col];
            }
            colSum[col] = tempSum;
        }

        bool check = false;
        ll chkSum = 0;
        for(ll i = 0; i < n; i++){
            if(chkSum == (totalSum - chkSum)){
                check = true;
            }
            chkSum += rowSum[i];
        }
        chkSum = 0;
        for(ll i = 0; i < m; i++){
            if(chkSum == (totalSum - chkSum)){
                check = true;
            }
            chkSum += colSum[i];
        }
        return check;
    }
};