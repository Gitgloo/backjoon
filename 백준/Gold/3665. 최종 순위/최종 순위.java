import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int n, m, enter[];

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());

        for(int i = 0; i < t; i++) {
            input();
            solve();
        }
    }

    static void solve() {
        int ans[] = new int[n];
        boolean flag = false;
        Queue<Integer> zeros = new LinkedList<>();

        for(int i = 1; i <= n; i++) {
            if(enter[i] == 0) {
                zeros.add(i);
            }
        }

        for(int i = 0; i < n; i++) {
            if(zeros.size() > 1) {
                flag = true;
            } else if(zeros.size() == 0) {
                System.out.println("IMPOSSIBLE");
                return;
            }

            int now = zeros.poll();
            ans[i] = now;
            for(int j = 1; j <= n; j++) {
                enter[j]--;
                if(enter[j] == 0) {
                    zeros.add(j);
                }
            }
        }

        if(flag) {
            System.out.println('?');
            return;
        }

        for(int i = 0; i < n; i++) {
            System.out.print(ans[i] + " ");
        }
        System.out.println();
    }

    static void input() throws IOException {
        StringTokenizer st;
        int[] last;

        n = Integer.parseInt(br.readLine());
        enter = new int[n + 1];
        last = new int[n + 1];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) {
            int t = Integer.parseInt(st.nextToken());

            last[t] = i;
            enter[t] = i;
        }

        m = Integer.parseInt(br.readLine());
        for(int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());

            if(last[a] < last[b]) {
                enter[a]++;
                enter[b]--;
            } else {
                enter[a]--;
                enter[b]++;
            }
        }
    }
}
