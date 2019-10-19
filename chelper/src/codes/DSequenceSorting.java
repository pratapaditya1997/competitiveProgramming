package codes;

import util.FastReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.TreeSet;

public class DSequenceSorting {
    public void solve(int testNumber, FastReader in, PrintWriter out) {
        int t = in.nextInt();
        for(int i=0;i<t;i++) {
            solver(in,out);
        }
    }

    private void solver(FastReader in, PrintWriter out) {
        Integer n = in.nextInt();

        int[] a = new int[n];
        int[] first = new int[n+1];
        int[] last = new int[n+1];

        Arrays.fill(first,Integer.MAX_VALUE);
        Arrays.fill(last,Integer.MIN_VALUE);

        TreeSet<Integer> set = new TreeSet<>();
        for(int i=0;i<n;i++){
            a[i] = in.nextInt();
            first[a[i]] = Math.min(first[a[i]],i);
            last[a[i]] = Math.max(last[a[i]],i);
            set.add(a[i]);
        }

        Integer[] arr = set.toArray(new Integer[set.size()]);
        int[] dp = new int[arr.length];
        Integer best = 1;

        dp[arr.length-1] = 1;
        for(int i = arr.length - 1; i > 0; i--) {
            if(last[arr[i-1]] < first[arr[i]]) {
                dp[i-1] = dp[i] + 1;
            } else dp[i-1] = 1;
            best = Math.max(best,dp[i-1]);
        }

        out.println(arr.length - best);
    }
}
