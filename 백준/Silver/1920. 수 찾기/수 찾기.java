import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);

        int m = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) {
            int find = Integer.parseInt(st.nextToken());
            sb.append(binarySearch(arr, n, find) + "\n");
        }

        System.out.println(sb);
    }

    public static int binarySearch(int[] arr, int n, int find){
        int left = 0, right = n - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(arr[mid] < find){
                left = mid + 1;
            } else if(arr[mid] > find){
                right = mid - 1;
            } else{
                return 1;
            }
        }

        return 0;
    }
}
