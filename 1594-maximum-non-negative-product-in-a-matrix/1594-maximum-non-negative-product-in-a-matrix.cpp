class Solution {
    using ll = long long;
    const int mod = 1e9 + 7;

    vector<vector<pair<ll,ll>>> dp;
    vector<vector<bool>> vis;

    pair<ll,ll> f(int i, int j, int n, int m, vector<vector<int>>& a) {
        if (i >= n || j >= m) {
            return {LLONG_MIN, LLONG_MAX};
        }

        if (i == n - 1 && j == m - 1) {
            return {a[i][j], a[i][j]};
        }

        if (vis[i][j]) return dp[i][j];

        auto down = f(i + 1, j, n, m, a);
        auto right = f(i, j + 1, n, m, a);

        ll mx = LLONG_MIN, mn = LLONG_MAX;

        vector<ll> candidates = {
            down.first, down.second,
            right.first, right.second
        };

        for (ll val : candidates) {
            if (val == LLONG_MIN || val == LLONG_MAX) continue;
            ll prod = val * a[i][j];
            mx = max(mx, prod);
            mn = min(mn, prod);
        }

        vis[i][j] = true;
        return dp[i][j] = {mx, mn};
    }

public:
    int maxProductPath(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();

        dp.assign(n, vector<pair<ll,ll>>(m));
        vis.assign(n, vector<bool>(m, false));

        auto res = f(0, 0, n, m, a);

        if (res.first < 0) return -1;
        return res.first % mod;
    }
};
