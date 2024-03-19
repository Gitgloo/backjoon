import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static Trie head = new Trie();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n, m, count = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for(int i = 0; i < n; i++) {
            makeTrie(br.readLine());
        }

        for(int i = 0; i < m; i++) {
            if(findWord(br.readLine())) {
                count++;
            }
        }

        System.out.println(count);
    }

    static boolean findWord(String str) {
        Trie now = head;

        for(int i = 0; i < str.length(); i++) {
            int ch = str.charAt(i) - 'a';

            if(now.arr[ch] == null) {
                return false;
            }

            now = now.arr[ch];
        }

        return now.end;
    }

    static void makeTrie(String str) {
        Trie now = head;

        for(int i = 0; i < str.length(); i++) {
            int ch = str.charAt(i) - 'a';

            if(now.arr[ch] == null) {
                now.arr[ch] = new Trie();
            }

            now = now.arr[ch];
        }

        now.end = true;
    }

    static class Trie {
        Trie[] arr = new Trie[26];
        boolean end = false;
    }
}
