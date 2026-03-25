#define mod 12345
class Solution {
    using ll=long long;
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>&a) {
        ll n=a.size();
        ll m=a[0].size();
        
        vector<vector<int>>ans(n,vector<int>(m));
        ll suf=1;
        for(ll i=n-1; i>=0; i--){
            for(ll j=m-1; j>=0; j--){
                ans[i][j]=suf;
                suf=(suf*a[i][j])%mod;
            }
        }
        
        ll pre=1;
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                ans[i][j]=(ans[i][j]*pre)%mod;
                pre=(pre*a[i][j])%mod;
            }
        }
        return ans;
    }
};