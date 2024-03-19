import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int n, m;
    static int[] enter;
    static List<Integer>[] nextNodes;

    public static void main(String[] args) throws IOException {
        input();
        solve();
    }

    public static void solve() {
        Queue<Integer> zeros = new LinkedList<>();
        StringBuilder sb = new StringBuilder();

        for(int i = 1; i <= n; i++) {
            if(enter[i] == 0) {
                zeros.add(i);
            }
        }

        for(int i = 0; i < n; i++) {
            int now = zeros.poll();

            sb.append(now + " ");
            for(int next : nextNodes[now]) {
                enter[next]--;
                if(enter[next] == 0) {
                    zeros.add(next);
                }
            }
        }

        System.out.println(sb);
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        enter = new int[n + 1];
        nextNodes = new List[n + 1];
        for(int i = 1; i <= n; i++){
            nextNodes[i] = new ArrayList<>();
        }

        for(int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());

            enter[b]++;
            nextNodes[a].add(b);
        }
    }
}