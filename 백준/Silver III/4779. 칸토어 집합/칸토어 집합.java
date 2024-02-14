import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
/*
짝대기로 초기화하고 빈칸이어야 하는 곳을 찾아서 빈 칸으로 바꾸기 보다는
sb를 길이만큼 선언만 하고
짝대기인 곳은 짝대기로
빈 칸인 곳은 빈 칸으로하면
빈 칸이어야 하는 곳을 짝대기로 선언하는 과정이 없어져서 좋을거 같다고 생각했어

그리고 N은 어차피 3^N으로 쓸거니깐 그냥 총 길이(3^N) 변수 하나 추가했어 
* */
public class Main {
    static StringBuilder sb = new StringBuilder();

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
                sb.setLength(len);  // 그래서 아예 처음부터 필요한 길이만큼 선언하고

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
                System.out.println(sb); // sb 그냥 이렇게 해도 될거야 그 오버라이딩인가 오버로딩인가 돼있을거니깐
            }

        }catch(Exception e){
            e.printStackTrace();
        }

    }

    static void makeCantorSet(int startIdx, int len){
//        System.out.println(startIdx + ", " + len + ", " + sb.toString());

        if(len == 1){
            sb.setCharAt(startIdx, '-');    // 추가
            return;
        }

        int subStrLen = len / 3;


//        System.out.println("subStrLen: " + subStrLen);

        // 왼쪽
        makeCantorSet(startIdx, subStrLen);

        // 중간
        for(int i = subStrLen; i < subStrLen * 2; i++){
            sb.setCharAt(startIdx + i, ' ');
        }


        // 오른쪽
        makeCantorSet(startIdx + subStrLen * 2, subStrLen);

    }
}
