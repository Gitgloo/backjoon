class Solution {
    public String solution(int n, int t, int m, int p) {
        String answer = "";
        int repeat = t * m;
        char arr[] = new char[repeat + 1];
        
        int nowNum = 0;
        int index = 0;
        outer : while(true) {
            String now = Integer.toString(nowNum++, n);
            for(int i = 0; i < now.length(); i++) {
                if(index == repeat)
                    break outer;
                
                char ch = now.charAt(i);
                
                if(ch >= 'a' && ch <= 'z')
                    ch += 'A' - 'a';
                
                arr[index++] = ch;
            }
        }
        
        for(int i = 0; i < t; i++) {
            answer += arr[p - 1 + i * m];
        }
        
        return answer;
    }
}