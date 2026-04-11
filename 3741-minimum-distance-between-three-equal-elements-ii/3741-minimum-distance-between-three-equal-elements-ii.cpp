class Solution {
    using ll=long long;
public:
    int minimumDistance(vector<int>&a) {
        ll n=a.size();
        map<ll,vector<ll>>mp;
        for(ll i=0; i<n; i++){
            mp[a[i]].push_back(i);
        }
        ll ans=1e12;
        for(auto& [_, v]: mp){
            if(v.size()<3) continue;
            ll mi=1e12;
            for(ll j=0; j<=(ll)v.size()-3; j++){
                ll p=abs(v[j]-v[j+1]);
                ll q=abs(v[j+1]-v[j+2]);
                ll r=abs(v[j+2]-v[j]);

                mi=min(mi,(p+q+r));
            }
            ans=min(ans,mi);
        }
        return ans==1e12 ? -1 : ans;
    }
};