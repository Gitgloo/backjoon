import java.util.*;

class Solution {
    static CacheMemory[] cache;
    static int cityIndex = 1;
    static Map<String, Integer> map = new HashMap<>();
    
    public int solution(int cacheSize, String[] cities) {
        int answer = 0;
        
        cacheInit(cacheSize);
        
        for(int i = 0; i < cities.length; i++) {
            int cityIndex = getCityIndex(cities[i]);
            
            answer += findCityInCache(cityIndex, i);
        }
        
        return answer;
    }
    
    int findCityInCache(int cityIndex, int step) {
        if(cache.length == 0)
            return 5;
        
        int minStep = 1000000;
        int minIndex = -1;
        
        for(int i = 0; i < cache.length; i++) {
            if(cityIndex == cache[i].cityIndex) {
                cache[i].step = step;
                return 1;
            }
            
            if(cache[i].cityIndex == 0) {
                cache[i].step = step;
                cache[i].cityIndex = cityIndex;
                return 5;
            }
            
            if(minStep > cache[i].step) {
                minStep = cache[i].step;
                minIndex = i;
            }
        }
        
        cache[minIndex].cityIndex = cityIndex;
        cache[minIndex].step = step;
        
        return 5;
    }
    
    void cacheInit(int cacheSize) {
        cache = new CacheMemory[cacheSize];
        
        for(int i = 0; i < cacheSize; i++) {
            cache[i] = new CacheMemory();
        }
    }
    
    int getCityIndex(String city) {
        String temp = city.toLowerCase();
        
            
        if(!map.containsKey(temp)) {
            map.put(temp, cityIndex++);
        }
            
        return map.get(temp);
    }
    
    class CacheMemory {
        int step;
        int cityIndex;
    }
}