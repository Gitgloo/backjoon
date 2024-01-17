import java.util.Scanner;

public class Main {

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] arr = new int[n];
        int[] operation = new int[4];
        Answer answer = new Answer();

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        for (int i = 0; i < 4; i++) {
            operation[i] = sc.nextInt();
        }

        recur(n, 1, arr[0], arr, operation, answer);

        System.out.println(answer.max);
        System.out.println(answer.min);
    }

    public static void recur(int n, int index, int sum, int[] arr, int[] operation, Answer answer) {
        if(index == n){
            answer.max = Math.max(answer.max, sum);
            answer.min = Math.min(answer.min, sum);
            return;
        }

        if(operation[0] > 0){
            operation[0]--;
            recur(n, index + 1, sum + arr[index], arr, operation, answer);
            operation[0]++;
        }

        if(operation[1] > 0){
            operation[1]--;
            recur(n, index + 1, sum - arr[index], arr, operation, answer);
            operation[1]++;
        }

        if(operation[2] > 0){
            operation[2]--;
            recur(n, index + 1, sum * arr[index], arr, operation, answer);
            operation[2]++;
        }

        if(operation[3] > 0){
            operation[3]--;
            recur(n, index + 1, sum / arr[index], arr, operation, answer);
            operation[3]++;
        }
    }

    static class Answer{
        int max = -1000000000;
        int min = 1000000000;
    }
}
