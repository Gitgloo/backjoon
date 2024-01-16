import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();

        int n = sc.nextInt();

        sb.append((1 << n) - 1 + "\n");
        recur(sb, n, 1, 3);

        System.out.print(sb);
    }

    public static void recur(StringBuilder sb, int n, int from, int to) {
        if(n == 0)
            return;

        recur(sb, n - 1, from, (1 + 2 + 3) - from - to);
        sb.append(from + " " + to + '\n');
        recur(sb, n - 1, (1 + 2 + 3) - from - to, to);
    }
}
