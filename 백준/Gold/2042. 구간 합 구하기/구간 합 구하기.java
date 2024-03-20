import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int n, q, maxIndex;
    static long tree[];

    public static void main(String[] args) throws IOException {
        init();
        solve();
    }

    static long find(int findLeft, int findRight, int treeLeft, int treeRight, int treeIndex) {
        if(findLeft == treeLeft && findRight == treeRight) return tree[treeIndex];

        int mid = (treeLeft + treeRight) / 2;

        if(findLeft <= mid && findRight > mid)
            return find(findLeft, mid, treeLeft, mid, 2 * treeIndex) + find(mid + 1, findRight, mid + 1, treeRight, 2 * treeIndex + 1);

        if(findRight <= mid)
            return find(findLeft, findRight, treeLeft, mid, 2 * treeIndex);

        // if(findLeft > mid)
            return find(findLeft, findRight, mid + 1, treeRight, 2 * treeIndex + 1);
    }
    static long find(int left, int right) {
        return find(left, right, 1, maxIndex, 1);
    }

    static long change(int treeLeft, int treeRight, int treeIndex, int index, long value) {

        if(index < treeLeft || index > treeRight)   return tree[treeIndex];
        if(treeLeft == treeRight) return tree[treeIndex] = value;

        int mid = (treeLeft + treeRight) / 2;
        return tree[treeIndex] = change(treeLeft, mid, 2 * treeIndex, index, value) + change(mid + 1, treeRight, 2 * treeIndex + 1, index, value);
    }

    static void change(int index, long value) {
        change(1, maxIndex, 1, index, value);
    }

    static void solve() throws IOException {
        StringBuilder sb = new StringBuilder();


        for(int i = 0; i < q; i++) {
            int a, b;
            long c;

            StringTokenizer st = new StringTokenizer(br.readLine());

            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Long.parseLong(st.nextToken());

            if(a == 1) {
                change(b, c);
            } else {
                sb.append(find(b, (int)c) + "\n");
            }
        }

        System.out.print(sb);
    }

    static void init() throws IOException {
        int size = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        q = Integer.parseInt(st.nextToken()) + Integer.parseInt(st.nextToken());

        while((1 << size) <= n) {
            size++;
        }

        tree = new long[1 << (size + 1)];
        maxIndex = 1 << size;

        for(int i = 1; i <= n; i++) {
            change(i, Long.parseLong(br.readLine()));
        }
    }
}