import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static int n, enter[];
    static List<Integer> nextProblems[];

    public static void main(String[] args) throws IOException {
        input();
        solve();
    }

    static void solve() {
        StringBuilder sb = new StringBuilder();
        PriorityQueue<Integer> zeros = new PriorityQueue<>();

        for(int i = 1; i <= n; i++) {
            if(enter[i] == 0){
                zeros.add(i);
            }
        }

        for(int i = 0; i < n; i++) {
            int now = zeros.poll();

            for(int next : nextProblems[now]) {
                enter[next]--;
                if(enter[next] == 0) {
                    zeros.add(next);
                }
            }
            sb.append(now + " ");
        }

        System.out.println(sb);
    }

    static void input() throws IOException {
        int m;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        enter = new int[n + 1];
        nextProblems = new List[n + 1];
        for(int i = 1; i <= n; i++) {
            nextProblems[i] = new ArrayList<>();
        }

        for(int i = 0; i < m; i++) {
            int a, b;

            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            enter[b]++;
            nextProblems[a].add(b);
        }
    }
}