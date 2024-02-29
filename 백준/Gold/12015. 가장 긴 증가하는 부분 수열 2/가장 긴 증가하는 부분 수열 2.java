import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int n, arr[], dp[], maxIdx = 1;

    public static void main(String[] args) throws IOException {
        input();
        solve();
    }

    static void solve() {
        for(int num : arr){
            int left = 1, right = n;

            while(left <= right){
                int mid = (left + right) / 2;

                if(dp[mid] < num) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            dp[left] = Math.min(dp[left], num);
        }

        int maxLen = 1;
        for(; dp[maxLen] != 1000001; maxLen++);
        System.out.println(maxLen - 1);
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        arr = new int[n];
        dp = new int[n + 2];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        for(int i = 1; i < n + 2; i++) {
            dp[i] = 1000001;
        }
    }
}