import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.StringTokenizer;

public class Main {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int table[][];

    public static void main(String[] args) throws IOException {
        init();
        solve();
    }

    private static void solve() throws IOException {
        int q = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        for(int i = 0; i < q; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            int n = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());

            for(int j = 0; 1 << j <= n; j++) {
                if((n & (1 << j)) > 0) {
                    x = table[j][x];
                }
            }

            sb.append(x + "\n");
        }

        System.out.println(sb);
    }

    private static void init() throws IOException {
        int m = Integer.parseInt(br.readLine());
        int move = 1;
        StringTokenizer st;

        while(1 << move < 500000) {
            move++;
        }

        table = new int[move][m + 1];

        st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= m; i++) {
            table[0][i] = Integer.parseInt(st.nextToken());
        }

        for(int i = 1; i < move; i++) {
            for(int j = 1; j <= m; j++) {
                table[i][j] = table[i - 1][table[i - 1][j]];
            }
        }
    }
}