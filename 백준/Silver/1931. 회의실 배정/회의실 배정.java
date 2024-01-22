import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        int count = 0;
        Meeting[] arr = new Meeting[n];
        for(int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            arr[i] = new Meeting(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }

        Arrays.sort(arr, (a, b) -> {
            if(a.end == b.end)
                return a.start - b.start;
            return a.end - b.end;
        });

        int endTime = 0;
        for (Meeting meeting : arr) {
            if(endTime <= meeting.start){
                count++;
                endTime = meeting.end;
            }
        }

        System.out.println(count);
    }

    static class Meeting{
        int start;
        int end;

        Meeting(int start, int end){
            this.start = start;
            this.end = end;
        }

    }
}
