class Solution {
    long[][] dp;
    long[] ops;

    private class DualHeap {

        PriorityQueue<Integer> left = new PriorityQueue<>(
            Comparator.reverseOrder()
        );
        PriorityQueue<Integer> right = new PriorityQueue<>();
        Map<Integer, Integer> delayed = new HashMap<>();
        int leftSize = 0,
            rightSize = 0;
        long sumL = 0,
            sumR = 0;

        void prune(PriorityQueue<Integer> heap) {
            while (
                !heap.isEmpty() && delayed.getOrDefault(heap.peek(), 0) > 0
            ) {
                int num = heap.poll();
                delayed.put(num, delayed.get(num) - 1);
            }
        }

        void balance() {
            if (leftSize > rightSize + 1) {
                int num = left.poll();
                right.offer(num);
                sumR += num;
                sumL -= num;
                ++rightSize;
                --leftSize;
                prune(left);
            } else if (rightSize > leftSize) {
                int num = right.poll();
                left.offer(num);
                sumL += num;
                sumR -= num;
                ++leftSize;
                --rightSize;
                prune(right);
            }
        }

        void add(int num) {
            if (left.isEmpty() || num <= left.peek()) {
                left.offer(num);
                ++leftSize;
                sumL += num;
            } else {
                right.offer(num);
                ++rightSize;
                sumR += num;
            }
            balance();
        }

        void remove(int num) {
            delayed.put(num, delayed.getOrDefault(num, 0) + 1);
            if (num <= left.peek()) {
                --leftSize;
                sumL -= num;
                if (num == left.peek()) {
                    prune(left);
                }
            } else {
                --rightSize;
                sumR -= num;
                if (num == right.peek()) {
                    prune(right);
                }
            }
            balance();
        }
    }

    public long solve(int i, int[] nums, int x, int k, int n) {
        if (k == 0) return 0;
        if (i >= n && k > 0) return (long)1e15;
        
        if (dp[i][k] != -1) return dp[i][k];
        long ans = (long)1e15;
        if (i + x <= n && k > 0) {
            ans = Math.min(ans, Math.min(ops[i + x - 1] + solve(i + x, nums, x, k - 1, n), solve(i + 1, nums, x, k, n)));
        }

        return dp[i][k] = ans;
    }


    public long minOperations(int[] nums, int x, int k) {
        int n = nums.length;
        DualHeap heaps = new DualHeap();
        ops = new long[n];
        for (int i = 0; i < n; ++i) {
            heaps.add(nums[i]);
            if (i >= x) {
                heaps.remove(nums[i - x]);
            }
            if (i >= x - 1) {
                long mid = heaps.left.peek();
                ops[i] =
                    heaps.sumR -
                    heaps.sumL +
                    mid * (heaps.leftSize - heaps.rightSize);
            }
        }

        dp = new long[n + 1][k + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = -1;
            }
        }
        return solve(0, nums, x, k, n);
    }
}

//