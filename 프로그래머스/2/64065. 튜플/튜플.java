import java.util.*;

class Solution {
    public int[] solution(String s) {
        int[] answer;
        Set<Integer> set = new HashSet<>();
        List<List<Integer>> tuples = new ArrayList<>();
        
        String[] tupleList = s.split("\\{");
        
        for(int i = 2; i < tupleList.length; i++) {
            List<Integer> temp = new ArrayList<>();
            String[] numbers = tupleList[i].split(",");
            String[] lastNumber;
            
            for(int j = 0; j < numbers.length - 1; j++) {
                temp.add(Integer.parseInt(numbers[j]));    
            }
            
            lastNumber = numbers[numbers.length - 1].split("\\}");
            temp.add(Integer.parseInt(lastNumber[0]));
            tuples.add(temp);
        }
        
        Collections.sort(tuples, (a, b) -> a.size() - b.size());
        
        answer = new int[tuples.size()];
        for(int i = 0; i < tuples.size(); i++) {
            for(int num : tuples.get(i)) {
                if(!set.contains(num)){
                    set.add(num);
                    answer[i] = num;
                }
            }
        }
        
        return answer;
    }
}