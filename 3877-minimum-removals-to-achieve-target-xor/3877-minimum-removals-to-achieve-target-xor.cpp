class Solution {
    using ll = long long;

    ll f(ll i, ll x_or, vector<int>& a, int target, ll n, map<pair<ll,ll>, ll> &dp){
        if(i == n){
            if(x_or == target){
                return 0;
            }
            return LLONG_MIN;
        }

        if(dp.find({i, x_or}) != dp.end()) return dp[{i, x_or}];

        ll pick = 1 + f(i+1, x_or ^ a[i], a, target, n, dp);
        ll noPick = f(i+1, x_or, a, target, n, dp);

        return dp[{i, x_or}]=max(pick, noPick);
    }

public:
    int minRemovals(vector<int>& a, int target) {
        ll n = a.size();
        map<pair<ll,ll>, ll> dp;
        ll res = f(0, 0, a, target, n, dp);

        if(res < 0) return -1;
        return n - res;
    }
};
