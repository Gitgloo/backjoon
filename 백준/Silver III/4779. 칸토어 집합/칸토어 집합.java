import java.io.*;

/*
근데 굳이 sb 안쓰고 char 배열이나 ArrayList<Char> 써도 될 거 같아서 해봤어
변수 이름은 그냥 그대로 쓸게
* */
public class Main {
//    static StringBuilder sb = new StringBuilder();
    static char[] sb = null;

    public static void main(String[] args) throws IOException {
        try{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String str;
            while((str = br.readLine())!=null){
                int N = Integer.parseInt(str);
                int len = (int)Math.pow(3, N);  // 만약 2의 배수였으면 비트연산자로 할 수 있었을텐데 아쉬워
//              int len = (int)Math.pow(3, Integer.parseInt(str));  // N변수 지우고 이렇게 해도 되고
//                sb.setLength(0);
//                sb.setLength((int)Math.pow(3, N));  // 그래서 아예 처음부터 필요한 길이만큼 선언하고
//                sb.setLength(len);  // 그래서 아예 처음부터 필요한 길이만큼 선언하고
                sb = new char[len];

                /*
                처음에 모두 '-'로 초기화 하지 않고
                makeCantorSet 함수에서 짝대기인 곳은 짝대기로, 빈 칸은 빈 칸으로
//                for(int i = 0; i < Math.pow(3, N); i++){
                for(int i = 0; i < len; i++){
//                    sb.append("-");
                    sb.setCharAt(i, '-');   // 모두 '-'로 초기화
                }
                */

//                System.out.println(line.length());

//                makeCantorSet(0, sb.length());
                makeCantorSet(0, len);  // len으로 대체!
//                System.out.println(sb.toString());
//                System.out.println(sb); // sb 그냥 이렇게 해도 될거야 그 오버라이딩인가 오버로딩인가 돼있을거니깐
                // 처음에 반복분 돌리면서 한 글자씩 Sout하니깐 시간초과뜨더라고
                // 찾아보니깐 StringBuilder도 이런식으로 한대
                // char[]를 가지고 쓰는게 맞더라고
                System.out.println(new String(sb));
            }

        }catch(Exception e){
            e.printStackTrace();
        }

    }

    static void makeCantorSet(int startIdx, int len){
//        System.out.println(startIdx + ", " + len + ", " + sb.toString());

        if(len == 1){
//            sb.setCharAt(startIdx, '-');    // 처음에 짝대기로 초기화 안해줫으니깐 추가
            sb[startIdx] = '-'; // 배열에 직접 접근
            return;
        }

        int subStrLen = len / 3;


//        System.out.println("subStrLen: " + subStrLen);

        // 왼쪽
        makeCantorSet(startIdx, subStrLen);

        // 중간
        for(int i = subStrLen; i < subStrLen * 2; i++){
            sb[startIdx + i] = ' '; // 배열에 직접 접근
        }


        // 오른쪽
        makeCantorSet(startIdx + subStrLen * 2, subStrLen);

    }
}
