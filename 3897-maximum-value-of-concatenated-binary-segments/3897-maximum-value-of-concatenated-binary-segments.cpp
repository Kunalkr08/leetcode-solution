#define mod 1000000007
class Solution {
    using ll=long long;

    ll find_power(ll x, ll y){
        ll result=1;
        while(y>0){
            if(y%2==1){
                result=(result*1LL*x)%mod;
            }
            y/=2;
            x=(x*1LL*x)%mod;
        }
        return result;
    }

    // 2^5  --> 4^2
public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        ll n=nums1.size();
        vector<pair<ll,ll>>v,v1;
        for(ll i=0; i<n; i++){
            if(nums0[i]==0){
                v1.push_back({nums1[i],0});
            }
            else{
                v.push_back({nums1[i],nums0[i]});
            }
        }

        sort(v.begin(),v.end(),[&](pair<ll,ll>&x, pair<ll,ll>&y){
            if(x.first==y.first) return x.second>y.second;
            return y.first>x.first;
        });

        for(auto& it: v1){
            v.push_back(it);
        }

        ll ans=0;
        ll cnt=0;
        for(ll i=0; i<(ll)v.size(); i++){
            ll one=v[i].first, zero=v[i].second;
            cnt+=zero;
            ll tmp=cnt+1;
            while(one>0){
               ll res=tmp-1;
               ans=(ans+find_power(2,res))%mod;
               one--;
               tmp++;
            }
            cnt+=v[i].first;
        }
        return ans;
    }
};
/*
   conditions
   
   condition when number of zero count is zero.
   1. if number of zero count is zero then keep this in very last so that it will helps us to maximise the result.

   condition when number of zero count is greater then zero.
   1. if numbers of one count is same then sort the data based on zero count and keep the maximun zero  
      count first and then minimum zero later.

   2. if number of one count is more then anyway we have to sort the data based on higher   
      count of one.
*/
