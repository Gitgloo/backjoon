import java.util.*;

class Solution {
    public int solution(String str1, String str2) {
        int answer = 0;
        Map<String, Integer> str1Words = getStrWordsMap(str1);
        Map<String, Integer> str2Words = getStrWordsMap(str2);
        
        if(str1Words.size() == 0 && str2Words.size() == 0)
            return 65536;
        
        int sameWordsCount = getSameWordsCount(str1Words, str2Words);
        int totalWordsCount = getTotalWordsCount(str1Words, str2Words);
        
        
        return (int)((double)sameWordsCount / totalWordsCount * 65536);
    }
    
    int getTotalWordsCount(Map<String, Integer> str1Words, Map<String, Integer> str2Words) {
        int totalWordsCount = 0;
        Map<String, Integer> totalWords = new HashMap<>();
        
        for(String key : str1Words.keySet()) {
            totalWords.put(key, str1Words.get(key));
        }
        
        for(String key : str2Words.keySet()) {
            if(totalWords.containsKey(key)) {
                totalWords.put(key, Math.max(totalWords.get(key), str2Words.get(key)));    
            } else {
                totalWords.put(key, str2Words.get(key));    
            }
        }
        
        for(String key : totalWords.keySet()) {
            totalWordsCount += totalWords.get(key);
        }     
        
        return totalWordsCount;
    }
    
    int getSameWordsCount(Map<String, Integer> str1Words, Map<String, Integer> str2Words) {
        int sameWordsCount = 0;
        Set<String> keySet = str1Words.keySet();
        
        for(String key : keySet) {
            Integer count = str2Words.get(key);
            
            if(count != null) {
                sameWordsCount += Math.min(str1Words.get(key), count);
            }
        }
        
        return sameWordsCount;
    }
    
    Map<String, Integer> getStrWordsMap(String str) {
        Map<String, Integer> strWords = new HashMap<>();
        
        for(int i = 2; i <= str.length(); i++) {
            String temp = str.substring(i - 2, i).toLowerCase();
            if(isOnlyAlpha(temp)) {
                if(!strWords.containsKey(temp)) {
                    strWords.put(temp, 0);
                }
                strWords.put(temp, strWords.get(temp) + 1);
            }
        }
        
        return strWords;
    }
    
    boolean isOnlyAlpha(String word) {
        char ch1 = word.charAt(0);
        char ch2 = word.charAt(1);
        
        return ch1 >= 'a' && ch1 <= 'z' && ch2 >='a' && ch2 <='z';
    }
    
    void print(Map<String, Integer> map) {
        Set<String> set = map.keySet();
        for(String a : set) {
            System.out.println(a + " " + map.get(a));
        }
    }
}