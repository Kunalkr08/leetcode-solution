class Solution {
    int[][] dp;
    private int solve(int i, int j, String word1, String word2, int n, int m) {
        if (i == n) return m - j;
        if (j == m) return n - i;
        
        if(dp[i][j] != - 1) return dp[i][j];
        int ans = 1000000000;
        if (word1.charAt(i) == word2.charAt(j)) {
            ans = solve(i + 1, j + 1, word1, word2, n, m);
        }
        else {
            int delete = 1 + solve(i + 1, j , word1, word2, n, m);
            int replace = 1 + solve(i + 1, j + 1, word1, word2, n, m);
            int insert = 1 + solve(i, j + 1, word1, word2, n, m);
            ans = Math.min(ans, Math.min(delete, Math.min(replace, insert)));
        }

        return dp[i][j] = ans;
    }
    public int minDistance(String word1, String word2) {
        int n = word1.length();
        int m = word2.length();
        dp = new int[n + 1][m + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = -1;
            }
        }
        return solve(0, 0, word1, word2, n, m);
    }
}

// 1. equal --> i + 1, j + 1
// 2. insert --> i + 
// 3. replace --> i + 1, j + 1
// 4. delete --> 

// horse --> i
// ros --> j

// i = 0, j = 0
// insert --> j + 1