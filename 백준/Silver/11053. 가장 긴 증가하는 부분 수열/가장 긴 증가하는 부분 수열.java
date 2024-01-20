import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(), ans = 0;
        int[] arr = new int[n + 1];
        int[] dp = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            arr[i] = sc.nextInt();

            int max = 0;
            for (int j = 0; j < i; j++) {
                if(arr[j] < arr[i] && max < dp[j]){
                    max = dp[j];
                }
            }
            dp[i] = max + 1;
            ans = Math.max(ans, dp[i]);
        }

        System.out.println(ans);
    }
}
