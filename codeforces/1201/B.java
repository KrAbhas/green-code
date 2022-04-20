import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Set;
import java.util.HashMap;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

public class a {
	public static void main(String args[]) {
		InputStream inputstream = System.in;
		OutputStream outputstream = System.out;
		InputReader in = new InputReader(inputstream);
		PrintWriter out = new PrintWriter(outputstream);
		CF solver = new CF();
		solver.solve(in, out, 1);
		out.close();
	}
	
	static class CF {
		public void solve (InputReader in, PrintWriter out, int tt) {
			while (tt-- != 0) {
				int n = in.nextInt();
				long a[] = in.readLongArray(n);
				long s = 0;
				long m = 0;
				for (long i: a) {
					s += i;
					m = Math.max(m, i);
				}
				boolean ok = false;
				if (s % 2 == 0 && m <= s / 2) {
					ok = true;
				}
				if (ok)
					out.println("YES");
				else out.println("NO");
			}
		}
	}
	
	static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
        
        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long[] readLongArray(int n) {
            long[] x = new long[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextLong();
            }
            return x;
        }

    }
}
