public class Solution {

    public static void main(String[] args) {

        Solution solution = new Solution();
        System.out.println(solution.nthUglyNumber(10));
    }

    public int nthUglyNumber(int n) {

        if (n == 1) {
            return 1;
        }

        int dp[] = new int[n + 1];
        int idx = 0;
        dp[idx++] = 1;
        dp[idx++] = 1;


        int p2 = 1, p3 = 1, p5 = 1;
        while (--n > 0) {
            int v2 = dp[p2] * 2;
            int v3 = dp[p3] * 3;
            int v5 = dp[p5] * 5;
            dp[idx] = Math.min(Math.min(v2, v3), v5);
            if (v2 == dp[idx]) {
                p2++;
            }
            if (v3 == dp[idx]) {
                p3++;
            }
            if (v5 == dp[idx]) {
                p5++;
            }
            idx++;
        }
        return dp[--idx];
    }

}