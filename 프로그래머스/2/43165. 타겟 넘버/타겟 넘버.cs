using System;
using System.Collections.Generic;

public class Solution {
    public int[] move = {1, -1};
    public int[] number;
    public int lastIndex, dest, answer = 0;
    public void DFS(int index, int sum){
        if(index == lastIndex){
            if(sum == dest)
                answer++;
            return;
        }
        
        for(int i=0; i<2; i++){
            int node = number[index] * move[i];
            DFS(index+1, sum+node);
        }
        
    }
    public int solution(int[] numbers, int target) {
        lastIndex = numbers.Length;
        dest = target;
        number = numbers;
        
        DFS(0, 0);
        return answer;
    }
}