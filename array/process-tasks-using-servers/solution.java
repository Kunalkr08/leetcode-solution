class Solution {
    public int[] assignTasks(int[] servers, int[] tasks) {
        int n = servers.length;
        int m = tasks.length;

        // {availableTime, serverIndex, serverWeight}
        PriorityQueue<int[]> timetoLeave = new PriorityQueue<>(
            (a, b) -> {
                if (a[0] != b[0])
                    return Integer.compare(a[0], b[0]);
                return Integer.compare(a[1], b[1]);
            }
        );

        // {serverWeight, serverIndex}
        PriorityQueue<int[]> freeServer = new PriorityQueue<>(
            (a, b) -> {
                if (a[0] != b[0])
                    return Integer.compare(a[0], b[0]);
                return Integer.compare(a[1], b[1]);
            }
        );

        for (int j = 0; j < n; j++) {
            freeServer.offer(new int[]{servers[j], j});
        }

        int[] ans = new int[m];
        int currentTime = 0;

        for (int i = 0; i < m; i++) {

            currentTime = Math.max(currentTime, i);

            while (!timetoLeave.isEmpty() && timetoLeave.peek()[0] <= currentTime) {
                int[] temp = timetoLeave.poll();
                freeServer.offer(new int[]{temp[2], temp[1]});
            }

            if (freeServer.isEmpty()) {

                currentTime = timetoLeave.peek()[0];

                while (!timetoLeave.isEmpty() && timetoLeave.peek()[0] <= currentTime) {
                    int[] temp = timetoLeave.poll();
                    freeServer.offer(new int[]{temp[2], temp[1]});
                }
            }

            int[] temp = freeServer.poll();

            ans[i] = temp[1];

            timetoLeave.offer(new int[]{
                currentTime + tasks[i],
                temp[1],
                temp[0]
            });
        }

        return ans;
    }
}
