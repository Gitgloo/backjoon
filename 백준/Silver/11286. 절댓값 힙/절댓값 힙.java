import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PriorityQueue<Integer> pq = new PriorityQueue<>(new Comparator<Integer>(){
            public int compare(Integer a, Integer b) {
                if(Math.abs(a) == Math.abs(b)){
                    return a - b;
                } else{
                    return Math.abs(a) - Math.abs(b);
                }
            }
        });

        int n = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        while(n-- > 0) {
            int x = Integer.parseInt(br.readLine());

            if(x == 0){
                if(pq.isEmpty()){
                    sb.append("0\n");
                } else{
                    sb.append(pq.poll() + "\n");
                }
            } else{
                pq.add(x);
            }
        }

        System.out.print(sb);
    }
}
