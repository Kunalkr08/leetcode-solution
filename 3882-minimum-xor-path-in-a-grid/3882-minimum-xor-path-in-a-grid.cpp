class Solution {
    using ll = long long;


public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<vector<bool>>>vis(n, vector<vector<bool>>(m, vector<bool>(1024, false)));

        queue<tuple<ll,ll,ll>>q;

        q.push({0, 0, grid[0][0]});
        vis[0][0][grid[0][0]] = true;

        while(!q.empty()){
            auto [x, y, xr] = q.front();
            q.pop();

            if(x+1<n){
                ll xorVal=xr^grid[x+1][y];
                if(!vis[x+1][y][xorVal]){
                    q.push({x+1,y,xorVal});
                    vis[x+1][y][xorVal]=true;
                }
            }

            if(y+1<m){
                ll xorVal=xr^grid[x][y+1];
                if(!vis[x][y+1][xorVal]){
                    q.push({x,y+1,xorVal});
                    vis[x][y+1][xorVal]=true;
                }
            }
        }
        
        ll ans=0;
        for(ll i=0; i<1024; i++){
            if(vis[n-1][m-1][i]){
                ans=i;
                break;
            }
        }
        return ans;
    }
};

// dp[i][j]=