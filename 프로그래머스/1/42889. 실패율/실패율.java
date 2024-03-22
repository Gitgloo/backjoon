import java.util.*;

class Solution {
    public int[] solution(int N, int[] stages) {
        int[] answer = new int[N];
        List<Stage> stageList = new ArrayList<>();
        
        for(int i = 0; i < N + 2; i++) {
            stageList.add(new Stage(i));
        }
        
        for(int i = 0; i < stages.length; i++) {
            stageList.get(stages[i]).failCount++;
        }
        
        stageList.get(N + 1).totalCount = stageList.get(N + 1).failCount;
        for(int i = N + 1; i > 0; i--) {
            stageList.get(i - 1).totalCount += stageList.get(i - 1).failCount + stageList.get(i).totalCount;
        }
        
        Collections.sort(stageList);
        int index = 0;
        for(Stage stage : stageList) {
            if(stage.step == 0 || stage.step == N + 1)
                continue;
            answer[index++] = stage.step;
        }
        
        return answer;
    }
    
    class Stage implements Comparable<Stage>{
        int step, totalCount, failCount;
        
        double getRate() {
            if(totalCount == 0){
                return 0;
            }
            return (double)failCount / totalCount;
        }
        
        public int compareTo(Stage s) {
            if(this.getRate() == s.getRate()) {
                return this.step - s.step;
            }
            double temp = s.getRate() - this.getRate();
            if(temp > 0)
                return 1;
            else if(temp == 0)
                return 0;
            else
                return -1;
        }
        
        Stage(int step) {
            this.step = step;
        }
    }
}