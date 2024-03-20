import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int n, find1, find2, answer;
    private static boolean hasParent[];
    private static List<Integer> childArray[];

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());

        for(int i = 0; i < t; i++) {
            input();
            solve();
        }
    }

    private static int makeTree(int now) {
        int check = 0;

        List<Integer> childs = childArray[now];
        if(now == find1) {
            check = 1;
        }

        if(now == find2) {
            check = 2;
        }

        for(int child : childs) {
            if(check == 3) {
                break;
            }

            check |= makeTree(child);
        }

        if(answer == 0 && check == 3) {
            answer = now;
        }

        return check;
    }

    private static void solve() {
        int root = 0;

        answer = 0;
        for(int i = 1; i <= n; i++) {
            if(hasParent[i] == false) {
                root = i;
                break;
            }
        }
        makeTree(root);
        System.out.println(answer);
    }

    private static void input() throws IOException {
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());
        childArray = new List[n + 1];
        hasParent = new boolean[n + 1];

        for(int i = 1; i <= n; i++) {
            childArray[i] = new ArrayList<>();
        }

        for(int i = 1; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            childArray[a].add(b);
            hasParent[b] = true;
        }

        st = new StringTokenizer(br.readLine());
        find1 = Integer.parseInt(st.nextToken());
        find2 = Integer.parseInt(st.nextToken());
    }
}