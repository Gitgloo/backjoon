import java.util.*;

class Solution {
    public int[] solution(String msg) {
        int index = 27;
        int[] answer = {};
        Map<String, Integer> dict = getNewDict();
        List<Integer> list = new ArrayList<>();
        
        for(int i = 0; i < msg.length();) {
            int result = 0;
            int j = i + 1;
            for(; j <= msg.length(); j++) {
                String temp = msg.substring(i, j);
                if(!dict.containsKey(temp)) {
                    dict.put(temp, index++);
                    break;
                }
                result = dict.get(temp);
            }
            
            if(i + 1 == j) {
                i++;
            } else {
                i = j - 1;
            }
            list.add(result);
        }
        
        answer = new int[list.size()];
        for(int i = 0; i < list.size(); i++){
            answer[i] = list.get(i);
        }
        
        return answer;
    }
    
    Map<String, Integer> getNewDict() {
        Map<String, Integer> dict = new HashMap<>();
        
        int index = 1;
        for(char ch = 'A'; ch <= 'Z'; ch++) {
            dict.put(ch + "", index++);
        }
        
        return dict;
    }
}