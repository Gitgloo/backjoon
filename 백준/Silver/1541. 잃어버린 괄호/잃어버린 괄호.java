import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int result = 0, temp = 0, minus = 0;
        String input = br.readLine();

        int i = 0;
        for(; i < input.length() && input.charAt(i) != '-'; i++) {
            char ch = input.charAt(i);

            if(ch == '+') {
                result += temp;
                temp = 0;
            } else {
                temp = 10 * temp + ch - '0';
            }
        }

        result += temp;
        temp = 0;

        for(; i < input.length(); i++) {
            char ch = input.charAt(i);

            if(ch == '+') {
                minus += temp;
                temp = 0;
            } else if(ch == '-') {
                result -= minus + temp;
                minus = 0;
                temp = 0;
            } else {
                temp = 10 * temp + ch - '0';
            }
        }

        result -= minus + temp;

        System.out.println(result);
    }
}
