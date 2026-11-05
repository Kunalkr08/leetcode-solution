class Solution {
    int[][] dp;
    public int solve (int i, int j, String s, String t, int n, int m) {
        if (i == n || j == m) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        if (s.charAt(i) == t.charAt(j)) {
            ans = Math.max(ans, 1 + solve(i + 1, j + 1, s, t, n, m));
        }
        else {
            ans = Math.max(ans, Math.max(solve(i + 1, j, s, t, n, m), solve(i, j + 1, s, t, n, m)));
        }

        return dp[i][j] = ans;
    }
    public int longestPalindromeSubseq(String s) {
        int n = s.length();
        StringBuilder rev = new StringBuilder();
        for (int index = 0; index < n; index++) {
            rev.append(s.charAt(n - index - 1));
        }
        String t = rev.toString();
        IO.println(s + " " + t);
        dp = new int[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = -1;
            }
        }
        return solve(0, 0, s, t, n, n);
    }
}