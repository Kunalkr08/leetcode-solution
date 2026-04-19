class Solution {
    using ll=long long;
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>&a) {
        vector<vector<int>>ans(n,vector<int>(m));
        vector<vector<int>>vis(n,vector<int>(m));

        queue<pair<pair<ll,ll>,ll>>q;
        int id=-1;
        for(auto& it: a){
            ll u=it[0], v=it[1], w=it[2];
            ans[u][v]=w;
            q.push({{u,v},w});
            vis[u][v]=id;
        }
        
        ll dx[4]={-1, 0, 1, 0};
        ll dy[4]={0, 1, 0, -1};

        while(!q.empty()){
            ll sz=q.size();
            id--;
            map<pair<ll,ll>,ll>mp;
            for(ll i=0; i<sz; i++){
                auto it=q.front();
                ll u=it.first.first;
                ll v=it.first.second;
                ll w=it.second;
                q.pop();

                for(ll j=0; j<4; j++){
                    ll nx=dx[j]+u;
                    ll ny=dy[j]+v;

                    if(nx>=0 && nx<n && ny>=0 && ny<m){
                        if(ans[nx][ny]==0){
                           ans[nx][ny]=w;
                           q.push({{nx,ny},w});
                           vis[nx][ny]=id;
                        }else if(vis[nx][ny]==id && w>ans[nx][ny]){
                           q.push({{nx,ny},w});
                           ans[nx][ny]=w;
                        }
                    }
                }

                for(auto& it: mp){
                    q.push({{it.first.first,it.first.second},it.second});
                }
            }
        }
        return ans;
    }
};