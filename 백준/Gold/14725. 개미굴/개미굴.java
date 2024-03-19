import java.util.*;

public class Main {
    static int n;
    static Trie head = new Trie();
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) {
        input();
        solve();
    }

    static void recur(Trie now, String lines) {
        List<String> foods = new ArrayList<>(now.map.keySet());

        Collections.sort(foods);
        /*foods.sort(new Comparator<String>() {
            @Override
            public int compare(String food1, String food2){
                return food1.compareTo(food2);
            }
        });*/
        //foods.sort((food1, food2) -> food1.compareTo(food2));

        foods.stream().forEach(food -> {
                sb.append(lines + food + '\n');
                recur(now.map.get(food), lines + "--");
        });

    }
    static void solve() {
        recur(head, "");
        System.out.println(sb);
    }

    static void input() {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        for(int i =0; i < n; i++) {
            int k = sc.nextInt();

            Trie now = head;
            for(int j = 0; j < k; j++) {
                String food = sc.next();

                if(!now.map.containsKey(food))
                    now.map.put(food, new Trie());
                now = now.map.get(food);
            }
        }
    }

}

class Trie{
    Map<String, Trie> map = new HashMap<>();
}
