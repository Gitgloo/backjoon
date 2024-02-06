import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0 ; i < n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);

        int m = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        while(m-- > 0) {
            int find = Integer.parseInt(st.nextToken());
            sb.append(upper(find, arr) - under(find, arr) + 1 + " ");
        }
        System.out.println(sb);
    }

    public static int upper(int find, int[] arr) {
        int left = 0, right = arr.length - 1;

        while(left <= right) {
            int mid = (left + right) / 2;

            if(arr[mid] > find){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }

    public static int under(int find, int[] arr) {
        int left = 0, right = arr.length - 1;

        while(left <= right) {
            int mid = (left + right) / 2;

            if(arr[mid] < find){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
}