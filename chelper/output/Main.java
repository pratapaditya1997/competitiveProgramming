import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.AbstractCollection;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author aps
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastReader in = new FastReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DSequenceSorting solver = new DSequenceSorting();
        solver.solve(1, in, out);
        out.close();
    }

    static class DSequenceSorting {
        public void solve(int testNumber, FastReader in, PrintWriter out) {
            int t = in.nextInt();
            for (int i = 0; i < t; i++) {
                solver(in, out);
            }
        }

        private void solver(FastReader in, PrintWriter out) {
            Integer n = in.nextInt();

            int[] a = new int[n];
            int[] first = new int[n + 1];
            int[] last = new int[n + 1];

            Arrays.fill(first, Integer.MAX_VALUE);
            Arrays.fill(last, Integer.MIN_VALUE);

            TreeSet<Integer> set = new TreeSet<>();
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
                first[a[i]] = Math.min(first[a[i]], i);
                last[a[i]] = Math.max(last[a[i]], i);
                set.add(a[i]);
            }

            Integer[] arr = set.toArray(new Integer[set.size()]);
            Integer[] dp = new Integer[arr.length];
            Integer best = 1;

            dp[arr.length - 1] = 1;
            for (int i = arr.length - 1; i > 0; i--) {
                if (last[arr[i - 1]] < first[arr[i]]) {
                    dp[i - 1] = dp[i] + 1;
                } else dp[i - 1] = 1;
                best = Math.max(best, dp[i - 1]);
            }

            out.println(arr.length - best);
        }

    }

    static class FastReader {
        private StringTokenizer tokenizer;
        private BufferedReader reader;

        public FastReader(InputStream inputStream) {
            reader = new BufferedReader(new InputStreamReader(inputStream));
        }

        public String nextToken() {
            try {
                while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                    tokenizer = new StringTokenizer(reader.readLine());
                }
                return tokenizer.nextToken();
            } catch (IOException e) {
                return null;
            }
        }

        public int nextInt() {
            return Integer.parseInt(nextToken());
        }

    }
}

