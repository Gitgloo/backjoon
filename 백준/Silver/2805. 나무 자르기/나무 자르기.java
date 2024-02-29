import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int n, m, arr[];

    public static void main(String[] args) {
        input();
        solve();
    }

    public static void solve(){
        long left = 1, right = 2147483647;

        while(left <= right){
            long mid = (left + right) / 2;
            long total = getTotal(mid);

            if(total < m){
                right = mid - 1;
            } else{
                left = mid + 1;
            }
        }

        System.out.println(right);
    }

    public static long getTotal(long height) {
        long total = 0;

        for(int tree : arr){
            if(tree > height)
                total += tree - height;
        }

        return total;
    }

    public static void input(){
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
        try {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());

            st = new StringTokenizer(br.readLine());
            arr = new int[n];
            for(int i = 0; i < n; i++){
                arr[i] = Integer.parseInt(st.nextToken());
            }
        } catch (IOException e) {
        }
    }
}
