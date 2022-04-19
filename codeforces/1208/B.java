
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
		/**
		 * @param in
		 * @param out
		 * @param tt
		 */
		public void solve (InputReader in, PrintWriter out, int tt) {
			int n = in.nextInt();
			int[] a = in.readIntArray(n);
			HashMap<Integer, Integer> freq = new HashMap<>();
			for (int x: a) {
				freq.put(x, 1 + freq.getOrDefault(x, 0));
			}
			int extra = n - freq.keySet().size();
			int r;
			for (r = 0; extra > 0; r++) {
				freq.put(a[r], freq.get(a[r]) - 1);
				if (freq.get(a[r]) >= 1)
					extra--;
			}
			
			int ans = r;
			outer:
			for (int i = 0; i < n; i++) {
				freq.put(a[i], freq.get(a[i]) + 1);
				if (freq.get(a[i]) > 1)
					extra++;
				for (; extra > 0; r++) {
					if (r == n)
						break outer;
					freq.put(a[r], freq.get(a[r]) - 1);
					if (freq.get(a[r]) >= 1)
						extra--;
				}
				ans = Math.min(ans, r - i - 1);
			}
			out.println(ans);
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

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public int[] readIntArray(int n) {
            int[] x = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }
            return x;
        }

    }
}
