package codes;

import util.FastReader;
import java.io.PrintWriter;

public class ACME {
    public void solve(int testNumber, FastReader in, PrintWriter out) {
        int t = in.nextInt();

        while(t-- > 0) {
            long n = in.nextLong();
            if(n == 2) out.println(2);
            else out.println(n % 2);
        }
    }
}
