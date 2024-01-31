import java.util.Scanner;

public class Main {
    static int[] count = { 0, 0 };
    static int[][] arr = null;

    public static void main(String[] args) {
        recur(0, 0, getInput());

        System.out.println(count[0] + "\n" + count[1]);
    }

    public static int getInput(){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        arr = new int[n][n];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                arr[i][j] = sc.nextInt();
            }
        }

        return n;
    }

    public static void recur(int r, int c, int size) {
        if(isSameColor(r, c, size)){
            count[arr[r][c]]++;
            return;
        }

        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                recur(r + i * size / 2, c + j * size / 2, size / 2);
            }
        }
    }

    public static boolean isSameColor(int r, int c, int size) {
        int color = arr[r][c];

        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                if(arr[r + i][c + j] != color){
                    return false;
                }
            }
        }

        return true;
    }
}
