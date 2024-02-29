import java.util.Scanner;

public class Main {
    static int n, k, arr[];

    public static void main(String[] args) {
        input();
        solve();
    }

    public static void solve(){
        long left = 1;
        long right = 2147483647;

        while(left <= right){
            long mid = (left + right) / 2;

            long count = getCount(mid);
            if(count < n){
                right = mid - 1;
            } else{
                left = mid + 1;
            }
        }

        System.out.println(right);
    }

    public static long getCount(long size) {
        long count = 0;

        for(int len : arr){
            count += len / size;
        }

        return count;
    }

    public static void input(){
        Scanner sc = new Scanner(System.in);

        k = sc.nextInt();
        n = sc.nextInt();
        arr = new int[k];
        for(int i = 0; i < k; i++){
            arr[i] = sc.nextInt();
        }
    }
}
