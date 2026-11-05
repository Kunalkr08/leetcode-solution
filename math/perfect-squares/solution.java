class Solution {
    int[] dp;
    public int solve(int[] arr, int sum, int n) {
        if (sum == 0) return 0;
        
        if (dp[sum] != -1) return dp[sum];
        int ans = 1000000001;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= sum) {
                ans = Math.min(ans, 1 + solve(arr, sum - arr[i], n));
            }
        }

        return dp[sum] = ans;
    }
    public int numSquares(int n) {

        dp = new int[n + 1];
        Arrays.fill(dp, -1);
        List<Integer> li = new ArrayList<>();
        for (int i = 1; i * i <= n; i++) {
            li.add(i * i);
        }

        int[] arr = new int[li.size()];
        for (int i = 0; i < li.size(); i++) {
            arr[i] = li.get(i);
        }

        int m = li.size();
        
        return solve(arr, n, m);
    }
}
