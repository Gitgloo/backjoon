import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        char[][] arr = new char[n][n];
        StringBuilder sb = new StringBuilder();

        recur(arr, n, 0, 0);
        for(int i = 0; i < n; i++) {
            for(int j= 0; j <n;j++) {
                sb.append(arr[i][j]);
            }
            sb.append('\n');
        }

        System.out.print(sb);
    }

    public static void blank(char[][] arr, int n, int x, int y){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                arr[x + i][y + j] = ' ';
            }
        }
    }

    public static void recur(char[][] arr, int n, int x, int y) {
        if(n == 1) {
            arr[x][y] = '*';
            return;
        }

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(i == 1 && j == 1)
                    blank(arr, n / 3, x + n / 3, y + n / 3);
                else
                    recur(arr, n / 3, x + i * n / 3, y + j * n / 3);
            }
        }
    }
}
