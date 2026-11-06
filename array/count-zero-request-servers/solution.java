
class Solution {
    public int[] countServers(int n, int[][] logs, int x, int[] queries) {

        Arrays.sort(logs, (a, b) ->
            Integer.compare(a[1], b[1])
        );

        int[][] q = new int[queries.length][2];

        for (int i = 0; i < queries.length; i++) {
            q[i][0] = queries[i];
            q[i][1] = i;
        }
        Arrays.sort(q, (a, b) ->
            Integer.compare(a[0], b[0])
        );

        int[] ans = new int[queries.length];
        Map<Integer, Integer> mp = new HashMap<>();

        int l = 0;
        int r = 0;
        for (int i = 0; i < q.length; i++) {

            int time = q[i][0];
            int start = time - x;

            // Add logs with timestamp <= time
            while (r < logs.length &&
                   logs[r][1] <= time) {

                int id = logs[r][0];

                mp.put(id, mp.getOrDefault(id, 0) + 1);
                r++;
            }

            // Remove logs with timestamp <= time - x
            while (l < r &&
                   logs[l][1] < start) {

                int id = logs[l][0];

                mp.put(id, mp.get(id) - 1);

                if (mp.get(id) == 0) {
                    mp.remove(id);
                }

                l++;
            }
            ans[q[i][1]] = n - mp.size();
        }

        return ans;
    }
}
