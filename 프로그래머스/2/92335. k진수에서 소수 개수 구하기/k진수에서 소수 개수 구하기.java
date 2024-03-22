class Solution {
    
    public int solution(int n, int k) {
        int answer = 0;
        String[] numbers = Integer.toString(n, k).split("0");
        for(String number : numbers) {
            if(number.length() > 0) {
                long num = Long.parseLong(number);
                if(num == 1)
                    continue;
                boolean flag = true;
                
                for(int i = 2; i <= Math.sqrt(num); i++) {
                    if(num % i == 0) {
                        flag = false;
                        break;
                    }
                }
                
                if(flag)
                    answer++;
            }
        }
        
        return answer;
    }
}