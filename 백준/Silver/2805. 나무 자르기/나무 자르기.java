import java.util.Scanner;

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
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();
        arr = new int[n];
        for(int i = 0; i < n; i++){
            arr[i] = sc.nextInt();
        }
    }
}