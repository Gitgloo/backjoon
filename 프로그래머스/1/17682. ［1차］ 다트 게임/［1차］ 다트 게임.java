import java.util.*;

class Solution {
    public int solution(String dartResult) {
        int answer = 0;
        List<Integer> record = new ArrayList<>();
        
        for(int i = 0; i < dartResult.length();) {
            int score = dartResult.charAt(i++) - '0';
            if(dartResult.charAt(i) == '0') {
                score = 10;
                i++;
            }
            char bonus = dartResult.charAt(i++);
            char option = 0;
            
            if(i < dartResult.length()) {
                option = dartResult.charAt(i);
                if(option == '*' || option == '#')
                    i++;
            }
            
            if(bonus == 'D'){
                score *= score;
            } else if(bonus == 'T') {
                score = score * score * score;
            }
            
            int before = record.size() - 1;
            if(option == '*') {
                if(before != -1) {
                    record.set(before, record.get(before) * 2);
                }
                score *= 2;
            } else if(option == '#') {
                score *= -1;
            }
            
            record.add(score);
        }
        
        for(int data : record) {
            answer += data;
        }
        
        return answer;
    }
}