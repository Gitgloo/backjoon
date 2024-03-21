class Solution {
    static String strToNum[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    static int length[] = {4, 3, 3, 5, 4, 4, 3, 5, 5, 4};
    
    public int solution(String s) {
        int answer = 0;
        
        int index = 0;
        while(index < s.length()) {
            if(isNum(s.charAt(index))) {
                answer = 10 * answer + s.charAt(index) - '0';
                index++;
            } else {
                int indexEnd = index;
                String temp = s.substring(index, s.length());
                    
                for(int i = 0; i < 10; i++) {
                    if(temp.startsWith(strToNum[i])) {
                        answer = 10 * answer + i;
                        index += length[i];
                        break;
                    }
                }
            }
        }
        
        return answer;
    }
    
    public static boolean isNum(char ch) {
        return ch >= '0' && ch <= '9';
    }
}