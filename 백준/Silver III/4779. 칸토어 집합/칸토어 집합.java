import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while(sc.hasNext()){
            int n = sc.nextInt();

            StringBuilder sb = new StringBuilder();
            recur(sb, n);
            System.out.println(sb);
        }
    }

    public static void recur(StringBuilder sb, int n) {
        if(n == 0){
            sb.append('-');
            return;
        }

        recur(sb, n - 1);
        space(sb, n - 1);
        recur(sb, n - 1);
    }

    public static void space(StringBuilder sb, int n) {
        int repeat = (int)Math.pow(3, n);

        while(repeat-- > 0) {
            sb.append(' ');
        }
    }
}
